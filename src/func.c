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

#define STRING_OPT(CNAME,SNAME) \
  else if (is_equal_symbol (option, CNAME)) \
    { \
      SCM_ASSERT (scm_is_string (x), x, SCM_ARG3, "curl-easy-setopt"); \
      code = curl_easy_setopt (c_handle, \
			       SNAME, \
			       scm_to_locale_string (x)); \
    }

#define LONG_OPT(CNAME,SNAME) \
  else if (is_equal_symbol (option, CNAME)) \
    { \
      SCM_ASSERT (scm_is_integer (x), x, SCM_ARG3, "curl-easy-setopt"); \
      code = curl_easy_setopt (c_handle, \
			       SNAME, \
			       scm_to_long (x)); \
    }

#define BOOL_OPT(CNAME,SNAME) \
  else if (is_equal_symbol (option, CNAME)) \
    { \
      SCM_ASSERT (scm_is_bool (x), x, SCM_ARG3, "curl-easy-setopt"); \
      code = curl_easy_setopt (c_handle, \
			       SNAME, \
			       scm_to_bool (x)); \
    }


SCM
cl_easy_setopt (SCM handle, SCM option, SCM x)
{
  CURL *c_handle;
  CURLcode code;

  SCM_ASSERT (_scm_is_handle (handle), handle, SCM_ARG1, "curl-easy-setopt");
  SCM_ASSERT (scm_is_symbol (option), option, SCM_ARG2, "curl-easy-setopt");

  c_handle = _scm_to_handle (handle);
  if (is_equal_symbol (option, "verbose"))
    {
      SCM_ASSERT (scm_is_bool (x), x, SCM_ARG3, "curl-easy-setopt");
      code = curl_easy_setopt (c_handle, 
			       CURLOPT_VERBOSE, 
			       scm_is_true(x) ? 1 : 0 );
    }

  /*******************/
  /* Network Options */
  /*******************/
  STRING_OPT("url", CURLOPT_URL)
    STRING_OPT("proxy", CURLOPT_PROXY)  
    LONG_OPT("proxyport", CURLOPT_PROXYPORT)
    LONG_OPT("proxytype", CURLOPT_PROXYTYPE)
    BOOL_OPT("httpproxytunnel", CURLOPT_HTTPPROXYTUNNEL)
    STRING_OPT("interface", CURLOPT_INTERFACE)
    LONG_OPT("localport", CURLOPT_LOCALPORT)
    LONG_OPT("localportrange", CURLOPT_LOCALPORTRANGE)
    LONG_OPT("dns-cache-timeout", CURLOPT_DNS_CACHE_TIMEOUT)
    LONG_OPT("port", CURLOPT_PORT)
    LONG_OPT("tcp-nodelay", CURLOPT_TCP_NODELAY)
    LONG_OPT("netrc", CURLOPT_NETRC)
    STRING_OPT("netrc-file", CURLOPT_NETRC_FILE)
  
  else
    abort ();

  return SCM_UNSPECIFIED;
}

SCM
cl_easy_perform (SCM handle)
{
  CURL *c_handle;
  SCM data;
  CURLcode status;

  SCM_ASSERT (_scm_is_handle (handle), handle, SCM_ARG1, "curl-easy-perform");

  c_handle = _scm_to_handle (handle);
  data = scm_c_make_string (0, SCM_MAKE_CHAR (0));

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
  size_t len;
  SCM string1, string2;

  string1 = *((SCM *)port);

  len = size * nmemb;

  /* printf ("In write_callback\n"); */


#if 0
  if (size == 1)
    data = scm_take_u8vector ((scm_t_uint8 *)ptr, nmemb);
  else if (size == 2)
    data = scm_take_u16vector ((scm_t_uint16 *)ptr, nmemb);
  else if (size == 4)
    data = scm_take_u32vector ((scm_t_uint32 *)ptr, nmemb);
  else 
    scm_error (SCM_BOOL_F,
	       "curl-easy-perform",
	       "libcurl returns unexpectedly-sized data",
	       SCM_BOOL_F,
	       SCM_BOOL_F);
#else
  string2 = scm_from_locale_stringn((char *)ptr, len);
#endif    

  string1 = scm_string_append (scm_list_2 (string1, string2));
  *((SCM *)port) = string1;

  return (len);
}

SCM
cl_easy_cleanup (SCM handle)
{
  CURL *c_handle;

  SCM_ASSERT (_scm_is_handle (handle), handle, SCM_ARG1, "curl-easy-perform");

  c_handle = _scm_to_handle (handle);

  curl_easy_cleanup (c_handle);

  return SCM_UNSPECIFIED;
}  

SCM
cl_global_cleanup ()
{
  curl_global_cleanup ();
  return SCM_UNDEFINED;
}

SCM
cl_global_init ()
{
  static int first = 1;
  static CURLcode ret;

  if (first)
    {
      first = 0;
      ret = curl_global_init (CURL_GLOBAL_ALL);
    }
  if (ret == 0)
    return SCM_BOOL_T;
  else
    return SCM_BOOL_F;
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
  CURLcode ret;
  if (first)
    {
      scm_c_define_gsubr ("%curl-easy-init", 0, 0, 0, cl_easy_init);
      scm_c_define_gsubr ("%curl-easy-setopt", 2, 1, 0, cl_easy_setopt);
      scm_c_define_gsubr ("%curl-easy-perform", 1, 0, 0, cl_easy_perform);
      scm_c_define_gsubr ("%curl-easy-handle", 1, 0, 0, cl_easy_cleanup);
      scm_c_define_gsubr ("%curl-global-cleanup", 0, 0, 0, cl_global_cleanup);
      scm_c_define_gsubr ("%curl-global-init", 0, 0, 0, cl_global_init);
      scm_c_define_gsubr ("%curl-error-string", 0, 0, 0, cl_error_string);
      scm_c_define_gsubr ("%curl-error-code", 0, 0, 0, cl_error_code);
    }
}
