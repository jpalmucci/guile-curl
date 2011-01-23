#include <libguile.h>
#include <curl/curl.h>
#include "type.h"

static scm_t_bits handle_tag;

SCM equalp_handle (SCM x1, SCM x2);
size_t gc_free_handle (SCM x);
SCM mark_handle (SCM x);
int print_handle (SCM x, SCM port, scm_print_state *pstate);


/* handle -- In C, a CURL *.  In Scheme, a smob that contains the pointer */

int 
_scm_is_handle (SCM x)
{
  return SCM_SMOB_PREDICATE (handle_tag, x);
}

CURL *
_scm_to_handle (SCM x)
{
  return (CURL *) SCM_SMOB_DATA (x);
}

SCM
_scm_from_handle (CURL *x)
{
  SCM s_handle;

  // assert (x != NULL);

  SCM_NEWSMOB (s_handle, handle_tag, x);

  // assert (x == (CURL *) SCM_SMOB_DATA (s_handle));

  if (0) 
    {
      fprintf (stderr, "Making <#handle> smob from CURL * %p\n", x);
    }

  return (s_handle);
}

// Handles are equal if they point to the same C structure
SCM
equalp_handle (SCM x1, SCM x2)
{
  CURL *handle1 = (CURL *) SCM_SMOB_DATA (x1);
  CURL *handle2 = (CURL *) SCM_SMOB_DATA (x2);

  if ((handle1 == NULL) || (handle2 == NULL))
    return SCM_BOOL_F;
  else if ((handle1 != handle2))
    return SCM_BOOL_F;
  else
    return SCM_BOOL_T;
}

SCM
mark_handle (SCM x)
{
  // No SCMs in the handle type: nothing to do here.
  return (SCM_BOOL_F);
}

/* The name is free_handle.  The curses primitive that frees memory is
   called del_handle. Note that del_handle doesn't free the underlying
   window. */
size_t
gc_free_handle (SCM handle)
{
  SCM_ASSERT (_scm_is_handle (handle), handle, SCM_ARG1, "free-handle");

  CURL *m = _scm_to_handle (handle);

  // assert (m != NULL);

  curl_easy_cleanup (m);

  return 0;
}

int
print_handle (SCM x, SCM port, scm_print_state *pstate)
{
  CURL *frm = (CURL *) SCM_SMOB_DATA (x);
  char *str;

  // assert (frm != NULL);

  scm_puts ("#<handle ", port);

  if (asprintf (&str, "%p", frm) < 0)
    scm_puts ("???", port);
  else
    scm_puts (str, port);

  scm_puts (">", port);
  
  // non-zero means success 
  return 1;
}

SCM
cl_is_handle_p (SCM x)
{
  return scm_from_bool (_scm_is_handle (x));
}

void 
cl_init_type ()
{
  handle_tag = scm_make_smob_type ("handle", sizeof (CURL *));
  scm_set_smob_mark (handle_tag, mark_handle);
  scm_set_smob_free (handle_tag, gc_free_handle);
  scm_set_smob_print (handle_tag, print_handle);
  scm_set_smob_equalp (handle_tag, equalp_handle);
  scm_c_define_gsubr ("handle?", 1, 0, 0, cl_is_handle_p);
}

