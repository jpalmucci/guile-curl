#include <libguile.h>
#include <curl/curl.h>
#include "type.h"
#include "func.h"

static size_t write_callback (void *ptr, size_t size, size_t nmemb, 
			      void *port);
static int is_equal_symbol (SCM sym, const char *str);

CURLcode error_code = CURLE_OK;
char error_string[CURL_ERROR_SIZE+1] = "";

SCM cl_easy_init ()
{
  CURL *handle;

  handle = curl_easy_init ();
  
  if (handle == NULL)
    {
      scm_error (SCM_BOOL_F,
		 "curl-easy-init",
		 "initialization failure",
		 SCM_BOOL_F,
		 SCM_BOOL_F);
    }
  
  return _scm_from_handle (handle);
}

static int
is_equal_symbol (SCM sym, const char *str)
{
  return (scm_is_true (scm_eq_p (sym, scm_from_locale_symbol (str))));
}

SCM
cl_easy_setopt (SCM handle, SCM option, SCM x, SCM big)
{
  CURL *c_handle;
  CURLcode code;
  CURLoption opt;
  char *opt_s;
  curl_off_t opt_off;

  SCM_ASSERT (_scm_is_handle (handle), handle, SCM_ARG1, "curl-easy-setopt");
  SCM_ASSERT (scm_is_integer (option), option, SCM_ARG2, "curl-easy-setopt");

  c_handle = _scm_to_handle (handle);
  opt = (CURLoption) scm_to_int (option);
  if (scm_is_integer (x))
    {
      if (scm_is_true (big))
	code = curl_easy_setopt (c_handle, opt, scm_to_int64 (x));
      else
	code = curl_easy_setopt (c_handle, opt, scm_to_long (x));
    }
  else if (scm_is_string (x))
    { 
      opt_s = scm_to_locale_string (x);
      code = curl_easy_setopt (c_handle, opt, opt_s);
      free (opt_s);
    }
  else if (scm_is_bytevector (x))
    code = curl_easy_setopt (c_handle, opt, SCM_BYTEVECTOR_CONTENTS (x));
  else if (_scm_is_slist (x))
    code = curl_easy_setopt (c_handle, opt, _scm_to_slist (x));
  else
    scm_error (SCM_BOOL_F,
	       "curl-easy-setopt",
	       "unimplemented option",
	       SCM_BOOL_F,
	       SCM_BOOL_F);

  return (code == CURLE_OK) ? SCM_BOOL_T : SCM_BOOL_F;
}

SCM
cl_easy_perform (SCM handle)
{
  CURL *c_handle;
  SCM data;
  CURLcode status;

  SCM_ASSERT (_scm_is_handle (handle), handle, SCM_ARG1, "curl-easy-perform");

  c_handle = _scm_to_handle (handle);
  if (c_handle == NULL)
    {
      error_code = CURLE_FAILED_INIT;
      return SCM_BOOL_F;
    }
  data = scm_c_make_bytevector (0);

  curl_easy_setopt (c_handle, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt (c_handle, CURLOPT_WRITEDATA, &data);
  curl_easy_setopt (c_handle, CURLOPT_ERRORBUFFER, error_string);

  /* Do the transfer, and fill c_str with the result */
  status = curl_easy_perform (c_handle);
  if (status != CURLE_OK)
    {
      error_code = status;
      return (SCM_BOOL_F);
    }
  else
    {
      return (data);
    }
}

/* This callback function catches the data passed by libcurl and sends
   it back as a scheme string */
static size_t 
write_callback (void *ptr, size_t size, size_t nmemb, void *port)
{
  size_t length1, length2;
  SCM data1, data2;

  data1 = *((SCM *)port);
  length1 = scm_c_bytevector_length (data1);

  length2 = size * nmemb;

  /* printf ("In write_callback\n"); */

  data2 = scm_c_make_bytevector (length1 + length2);
  memcpy (SCM_BYTEVECTOR_CONTENTS (data2),
	  SCM_BYTEVECTOR_CONTENTS (data1),
	  length1);
  memcpy (SCM_BYTEVECTOR_CONTENTS (data2) + length1,
	  ptr,
	  length2);
  *((SCM *)port) = data2;

  return (length2);
}

SCM
cl_easy_reset (SCM handle)
{
  CURL *c_handle;

  SCM_ASSERT (_scm_is_handle (handle), handle, SCM_ARG1, "%curl-easy-reset");

  c_handle = _scm_to_handle (handle);

  curl_easy_reset (c_handle);

  return SCM_UNSPECIFIED;
}

SCM
cl_easy_cleanup (SCM handle)
{
  CURL *c_handle;

  SCM_ASSERT (_scm_is_handle (handle), handle, SCM_ARG1, "%curl-easy-cleanup");

  c_handle = _scm_to_handle (handle);

  curl_easy_cleanup (c_handle);
  
  c_handle = (CURL *) NULL;

  return SCM_UNSPECIFIED;
}  

SCM
cl_error_string ()
{
  return (scm_from_locale_string (error_string));
}

SCM
cl_error_code ()
{
  return scm_from_int ((int) error_code);
}

void
cl_init_func ()
{
  static int first = 1;

  if (first)
    {
      scm_c_define_gsubr ("%curl-easy-init", 0, 0, 0, cl_easy_init);
      scm_c_define_gsubr ("%curl-easy-setopt", 4, 0, 0, cl_easy_setopt);
      scm_c_define_gsubr ("%curl-easy-perform", 1, 0, 0, cl_easy_perform);
      scm_c_define_gsubr ("%curl-easy-cleanup", 1, 0, 0, cl_easy_cleanup);
      scm_c_define_gsubr ("%curl-easy-reset", 1, 0, 0, cl_easy_reset);
      scm_c_define_gsubr ("%curl-error-string", 0, 0, 0, cl_error_string);
      scm_c_define_gsubr ("%curl-error-code", 0, 0, 0, cl_error_code);
      
      first = 0;
    }
}
