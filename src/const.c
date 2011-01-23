#include <libguile.h>
#include <curl/curl.h>
#include "const.h"

SCM cl_CURLE_OK;
SCM cl_CURLE_UNSUPPORTED_PROTOCOL;
SCM cl_CURLE_FAILED_INIT;
SCM cl_CURLE_URL_MALFORMAT;
SCM cl_CURLE_URL_MALFORMAT_USER;
SCM cl_CURLE_COULDNT_RESOLVE_PROXY;
SCM cl_CURLE_COULDNT_RESOLVE_HOST;
SCM cl_CURLE_COULDNT_CONNECT;
SCM cl_CURLE_FTP_WEIRD_SERVER_REPLY;
SCM cl_CURLE_FTP_ACCESS_DENIED;
SCM cl_CURLE_FTP_USER_PASSWORD_INCORRECT;
SCM cl_CURLE_FTP_WEIRD_PASS_REPLY;
SCM cl_CURLE_FTP_WEIRD_USER_REPLY;
SCM cl_CURLE_FTP_WEIRD_PASV_REPLY;
SCM cl_CURLE_FTP_WEIRD_227_FORMAT;
SCM cl_CURLE_FTP_CANT_GET_HOST;
SCM cl_CURLE_FTP_CANT_RECONNECT;
SCM cl_CURLE_FTP_COULDNT_SET_BINARY;
SCM cl_CURLE_PARTIAL_FILE;
SCM cl_CURLE_FTP_COULDNT_RETR_FILE;
SCM cl_CURLE_FTP_WRITE_ERROR;
SCM cl_CURLE_FTP_QUOTE_ERROR;
SCM cl_CURLE_HTTP_RETURNED_ERROR;
SCM cl_CURLE_WRITE_ERROR;
SCM cl_CURLE_MALFORMAT_USER;
SCM cl_CURLE_UPLOAD_FAILED;
SCM cl_CURLE_READ_ERROR;
SCM cl_CURLE_OUT_OF_MEMORY;
SCM cl_CURLE_OPERATION_TIMEOUTED;
SCM cl_CURLE_FTP_COULDNT_SET_ASCII;
SCM cl_CURLE_FTP_PORT_FAILED;
SCM cl_CURLE_FTP_COULDNT_USE_REST;
SCM cl_CURLE_FTP_COULDNT_GET_SIZE;
SCM cl_CURLE_HTTP_RANGE_ERROR;
SCM cl_CURLE_HTTP_POST_ERROR;
SCM cl_CURLE_SSL_CONNECT_ERROR;
SCM cl_CURLE_BAD_DOWNLOAD_RESUME;
SCM cl_CURLE_FILE_COULDNT_READ_FILE;
SCM cl_CURLE_LDAP_CANNOT_BIND;
SCM cl_CURLE_LDAP_SEARCH_FAILED;
SCM cl_CURLE_LIBRARY_NOT_FOUND;
SCM cl_CURLE_FUNCTION_NOT_FOUND;
SCM cl_CURLE_ABORTED_BY_CALLBACK;
SCM cl_CURLE_BAD_FUNCTION_ARGUMENT;
SCM cl_CURLE_BAD_CALLING_ORDER;
SCM cl_CURLE_INTERFACE_FAILED;
SCM cl_CURLE_BAD_PASSWORD_ENTERED;
SCM cl_CURLE_TOO_MANY_REDIRECTS;
SCM cl_CURLE_UNKNOWN_TELNET_OPTION;
SCM cl_CURLE_TELNET_OPTION_SYNTAX;
SCM cl_CURLE_OBSOLETE;
SCM cl_CURLE_SSL_PEER_CERTIFICATE;
SCM cl_CURLE_GOT_NOTHING;
SCM cl_CURLE_SSL_ENGINE_NOTFOUND;
SCM cl_CURLE_SSL_ENGINE_SETFAILED;
SCM cl_CURLE_SEND_ERROR;
SCM cl_CURLE_RECV_ERROR;
SCM cl_CURLE_SHARE_IN_USE;
SCM cl_CURLE_SSL_CERTPROBLEM;
SCM cl_CURLE_SSL_CIPHER;
SCM cl_CURLE_SSL_CACERT;
SCM cl_CURLE_BAD_CONTENT_ENCODING;
SCM cl_CURLE_LDAP_INVALID_URL;
SCM cl_CURLE_FILESIZE_EXCEEDED;
SCM cl_CURLE_FTP_SSL_FAILED;
SCM cl_CURLE_SEND_FAIL_REWIND;
SCM cl_CURLE_SSL_ENGINE_INITFAILED;
SCM cl_CURLE_LOGIN_DENIED;
SCM cl_CURLE_TFTP_NOTFOUND;
SCM cl_CURLE_TFTP_PERM;
SCM cl_CURLE_TFTP_DISKFULL;
SCM cl_CURLE_TFTP_ILLEGAL;
SCM cl_CURLE_TFTP_UNKNOWNID;
SCM cl_CURLE_TFTP_EXISTS;
SCM cl_CURLE_TFTP_NOSUCHUSER;
SCM cl_CURLE_CONV_FAILED;
SCM cl_CURLE_CONV_REQD;
SCM cl_CURLE_SSL_CACERT_BADFILE;
SCM cl_CURLE_REMOTE_FILE_NOT_FOUND;
SCM cl_CURLE_SSH;
SCM cl_CURLE_SSL_SHUTDOWN_FAILED;

SCM cl_CURLPROXY_HTTP;
SCM cl_CURLPROXY_SOCKS4;
SCM cl_CURLPROXY_SOCKS5;


void 
cl_init_const ()
{
  cl_CURLE_OK=scm_permanent_object(scm_c_define("CURLE_OK",scm_from_int((int)CURLE_OK)));
  cl_CURLE_UNSUPPORTED_PROTOCOL=scm_permanent_object(scm_c_define("CURLE_UNSUPPORTED_PROTOCOL",scm_from_int((int)CURLE_UNSUPPORTED_PROTOCOL)));
  cl_CURLE_FAILED_INIT=scm_permanent_object(scm_c_define("CURLE_FAILED_INIT",scm_from_int((int)CURLE_FAILED_INIT)));
  cl_CURLE_URL_MALFORMAT=scm_permanent_object(scm_c_define("CURLE_URL_MALFORMAT",scm_from_int((int)CURLE_URL_MALFORMAT)));
  cl_CURLE_URL_MALFORMAT_USER=scm_permanent_object(scm_c_define("CURLE_URL_MALFORMAT_USER",scm_from_int((int)CURLE_URL_MALFORMAT_USER)));
  cl_CURLE_COULDNT_RESOLVE_PROXY=scm_permanent_object(scm_c_define("CURLE_COULDNT_RESOLVE_PROXY",scm_from_int((int)CURLE_COULDNT_RESOLVE_PROXY)));
  cl_CURLE_COULDNT_RESOLVE_HOST=scm_permanent_object(scm_c_define("CURLE_COULDNT_RESOLVE_HOST",scm_from_int((int)CURLE_COULDNT_RESOLVE_HOST)));
  cl_CURLE_COULDNT_CONNECT=scm_permanent_object(scm_c_define("CURLE_COULDNT_CONNECT",scm_from_int((int)CURLE_COULDNT_CONNECT)));
  cl_CURLE_FTP_WEIRD_SERVER_REPLY=scm_permanent_object(scm_c_define("CURLE_FTP_WEIRD_SERVER_REPLY",scm_from_int((int)CURLE_FTP_WEIRD_SERVER_REPLY)));
  cl_CURLE_FTP_ACCESS_DENIED=scm_permanent_object(scm_c_define("CURLE_FTP_ACCESS_DENIED",scm_from_int((int)CURLE_FTP_ACCESS_DENIED)));
  cl_CURLE_FTP_USER_PASSWORD_INCORRECT=scm_permanent_object(scm_c_define("CURLE_FTP_USER_PASSWORD_INCORRECT",scm_from_int((int)CURLE_FTP_USER_PASSWORD_INCORRECT)));
  cl_CURLE_FTP_WEIRD_PASS_REPLY=scm_permanent_object(scm_c_define("CURLE_FTP_WEIRD_PASS_REPLY",scm_from_int((int)CURLE_FTP_WEIRD_PASS_REPLY)));
  cl_CURLE_FTP_WEIRD_USER_REPLY=scm_permanent_object(scm_c_define("CURLE_FTP_WEIRD_USER_REPLY",scm_from_int((int)CURLE_FTP_WEIRD_USER_REPLY)));
  cl_CURLE_FTP_WEIRD_PASV_REPLY=scm_permanent_object(scm_c_define("CURLE_FTP_WEIRD_PASV_REPLY",scm_from_int((int)CURLE_FTP_WEIRD_PASV_REPLY)));
  cl_CURLE_FTP_WEIRD_227_FORMAT=scm_permanent_object(scm_c_define("CURLE_FTP_WEIRD_227_FORMAT",scm_from_int((int)CURLE_FTP_WEIRD_227_FORMAT)));
  cl_CURLE_FTP_CANT_GET_HOST=scm_permanent_object(scm_c_define("CURLE_FTP_CANT_GET_HOST",scm_from_int((int)CURLE_FTP_CANT_GET_HOST)));
  cl_CURLE_FTP_CANT_RECONNECT=scm_permanent_object(scm_c_define("CURLE_FTP_CANT_RECONNECT",scm_from_int((int)CURLE_FTP_CANT_RECONNECT)));
  cl_CURLE_FTP_COULDNT_SET_BINARY=scm_permanent_object(scm_c_define("CURLE_FTP_COULDNT_SET_BINARY",scm_from_int((int)CURLE_FTP_COULDNT_SET_BINARY)));
  cl_CURLE_PARTIAL_FILE=scm_permanent_object(scm_c_define("CURLE_PARTIAL_FILE",scm_from_int((int)CURLE_PARTIAL_FILE)));
  cl_CURLE_FTP_COULDNT_RETR_FILE=scm_permanent_object(scm_c_define("CURLE_FTP_COULDNT_RETR_FILE",scm_from_int((int)CURLE_FTP_COULDNT_RETR_FILE)));
  cl_CURLE_FTP_WRITE_ERROR=scm_permanent_object(scm_c_define("CURLE_FTP_WRITE_ERROR",scm_from_int((int)CURLE_FTP_WRITE_ERROR)));
  cl_CURLE_FTP_QUOTE_ERROR=scm_permanent_object(scm_c_define("CURLE_FTP_QUOTE_ERROR",scm_from_int((int)CURLE_FTP_QUOTE_ERROR)));
  cl_CURLE_HTTP_RETURNED_ERROR=scm_permanent_object(scm_c_define("CURLE_HTTP_RETURNED_ERROR",scm_from_int((int)CURLE_HTTP_RETURNED_ERROR)));
  cl_CURLE_WRITE_ERROR=scm_permanent_object(scm_c_define("CURLE_WRITE_ERROR",scm_from_int((int)CURLE_WRITE_ERROR)));
  cl_CURLE_MALFORMAT_USER=scm_permanent_object(scm_c_define("CURLE_MALFORMAT_USER",scm_from_int((int)CURLE_MALFORMAT_USER)));
  cl_CURLE_UPLOAD_FAILED=scm_permanent_object(scm_c_define("CURLE_UPLOAD_FAILED",scm_from_int((int)CURLE_UPLOAD_FAILED)));
  cl_CURLE_READ_ERROR=scm_permanent_object(scm_c_define("CURLE_READ_ERROR",scm_from_int((int)CURLE_READ_ERROR)));
  cl_CURLE_OUT_OF_MEMORY=scm_permanent_object(scm_c_define("CURLE_OUT_OF_MEMORY",scm_from_int((int)CURLE_OUT_OF_MEMORY)));
  cl_CURLE_OPERATION_TIMEOUTED=scm_permanent_object(scm_c_define("CURLE_OPERATION_TIMEOUTED",scm_from_int((int)CURLE_OPERATION_TIMEOUTED)));
  cl_CURLE_FTP_COULDNT_SET_ASCII=scm_permanent_object(scm_c_define("CURLE_FTP_COULDNT_SET_ASCII",scm_from_int((int)CURLE_FTP_COULDNT_SET_ASCII)));
  cl_CURLE_FTP_PORT_FAILED=scm_permanent_object(scm_c_define("CURLE_FTP_PORT_FAILED",scm_from_int((int)CURLE_FTP_PORT_FAILED)));
  cl_CURLE_FTP_COULDNT_USE_REST=scm_permanent_object(scm_c_define("CURLE_FTP_COULDNT_USE_REST",scm_from_int((int)CURLE_FTP_COULDNT_USE_REST)));
  cl_CURLE_FTP_COULDNT_GET_SIZE=scm_permanent_object(scm_c_define("CURLE_FTP_COULDNT_GET_SIZE",scm_from_int((int)CURLE_FTP_COULDNT_GET_SIZE)));
  cl_CURLE_HTTP_RANGE_ERROR=scm_permanent_object(scm_c_define("CURLE_HTTP_RANGE_ERROR",scm_from_int((int)CURLE_HTTP_RANGE_ERROR)));
  cl_CURLE_HTTP_POST_ERROR=scm_permanent_object(scm_c_define("CURLE_HTTP_POST_ERROR",scm_from_int((int)CURLE_HTTP_POST_ERROR)));
  cl_CURLE_SSL_CONNECT_ERROR=scm_permanent_object(scm_c_define("CURLE_SSL_CONNECT_ERROR",scm_from_int((int)CURLE_SSL_CONNECT_ERROR)));
  cl_CURLE_BAD_DOWNLOAD_RESUME=scm_permanent_object(scm_c_define("CURLE_BAD_DOWNLOAD_RESUME",scm_from_int((int)CURLE_BAD_DOWNLOAD_RESUME)));
  cl_CURLE_FILE_COULDNT_READ_FILE=scm_permanent_object(scm_c_define("CURLE_FILE_COULDNT_READ_FILE",scm_from_int((int)CURLE_FILE_COULDNT_READ_FILE)));
  cl_CURLE_LDAP_CANNOT_BIND=scm_permanent_object(scm_c_define("CURLE_LDAP_CANNOT_BIND",scm_from_int((int)CURLE_LDAP_CANNOT_BIND)));
  cl_CURLE_LDAP_SEARCH_FAILED=scm_permanent_object(scm_c_define("CURLE_LDAP_SEARCH_FAILED",scm_from_int((int)CURLE_LDAP_SEARCH_FAILED)));
  cl_CURLE_LIBRARY_NOT_FOUND=scm_permanent_object(scm_c_define("CURLE_LIBRARY_NOT_FOUND",scm_from_int((int)CURLE_LIBRARY_NOT_FOUND)));
  cl_CURLE_FUNCTION_NOT_FOUND=scm_permanent_object(scm_c_define("CURLE_FUNCTION_NOT_FOUND",scm_from_int((int)CURLE_FUNCTION_NOT_FOUND)));
  cl_CURLE_ABORTED_BY_CALLBACK=scm_permanent_object(scm_c_define("CURLE_ABORTED_BY_CALLBACK",scm_from_int((int)CURLE_ABORTED_BY_CALLBACK)));
  cl_CURLE_BAD_FUNCTION_ARGUMENT=scm_permanent_object(scm_c_define("CURLE_BAD_FUNCTION_ARGUMENT",scm_from_int((int)CURLE_BAD_FUNCTION_ARGUMENT)));
  cl_CURLE_BAD_CALLING_ORDER=scm_permanent_object(scm_c_define("CURLE_BAD_CALLING_ORDER",scm_from_int((int)CURLE_BAD_CALLING_ORDER)));
  cl_CURLE_INTERFACE_FAILED=scm_permanent_object(scm_c_define("CURLE_INTERFACE_FAILED",scm_from_int((int)CURLE_INTERFACE_FAILED)));
  cl_CURLE_BAD_PASSWORD_ENTERED=scm_permanent_object(scm_c_define("CURLE_BAD_PASSWORD_ENTERED",scm_from_int((int)CURLE_BAD_PASSWORD_ENTERED)));
  cl_CURLE_TOO_MANY_REDIRECTS=scm_permanent_object(scm_c_define("CURLE_TOO_MANY_REDIRECTS",scm_from_int((int)CURLE_TOO_MANY_REDIRECTS)));
  cl_CURLE_UNKNOWN_TELNET_OPTION=scm_permanent_object(scm_c_define("CURLE_UNKNOWN_TELNET_OPTION",scm_from_int((int)CURLE_UNKNOWN_TELNET_OPTION)));
  cl_CURLE_TELNET_OPTION_SYNTAX=scm_permanent_object(scm_c_define("CURLE_TELNET_OPTION_SYNTAX",scm_from_int((int)CURLE_TELNET_OPTION_SYNTAX)));
  cl_CURLE_OBSOLETE=scm_permanent_object(scm_c_define("CURLE_OBSOLETE",scm_from_int((int)CURLE_OBSOLETE)));
  cl_CURLE_SSL_PEER_CERTIFICATE=scm_permanent_object(scm_c_define("CURLE_SSL_PEER_CERTIFICATE",scm_from_int((int)CURLE_SSL_PEER_CERTIFICATE)));
  cl_CURLE_GOT_NOTHING=scm_permanent_object(scm_c_define("CURLE_GOT_NOTHING",scm_from_int((int)CURLE_GOT_NOTHING)));
  cl_CURLE_SSL_ENGINE_NOTFOUND=scm_permanent_object(scm_c_define("CURLE_SSL_ENGINE_NOTFOUND",scm_from_int((int)CURLE_SSL_ENGINE_NOTFOUND)));
  cl_CURLE_SSL_ENGINE_SETFAILED=scm_permanent_object(scm_c_define("CURLE_SSL_ENGINE_SETFAILED",scm_from_int((int)CURLE_SSL_ENGINE_SETFAILED)));
  cl_CURLE_SEND_ERROR=scm_permanent_object(scm_c_define("CURLE_SEND_ERROR",scm_from_int((int)CURLE_SEND_ERROR)));
  cl_CURLE_RECV_ERROR=scm_permanent_object(scm_c_define("CURLE_RECV_ERROR",scm_from_int((int)CURLE_RECV_ERROR)));
  cl_CURLE_SHARE_IN_USE=scm_permanent_object(scm_c_define("CURLE_SHARE_IN_USE",scm_from_int((int)CURLE_SHARE_IN_USE)));
  cl_CURLE_SSL_CERTPROBLEM=scm_permanent_object(scm_c_define("CURLE_SSL_CERTPROBLEM",scm_from_int((int)CURLE_SSL_CERTPROBLEM)));
  cl_CURLE_SSL_CIPHER=scm_permanent_object(scm_c_define("CURLE_SSL_CIPHER",scm_from_int((int)CURLE_SSL_CIPHER)));
  cl_CURLE_SSL_CACERT=scm_permanent_object(scm_c_define("CURLE_SSL_CACERT",scm_from_int((int)CURLE_SSL_CACERT)));
  cl_CURLE_BAD_CONTENT_ENCODING=scm_permanent_object(scm_c_define("CURLE_BAD_CONTENT_ENCODING",scm_from_int((int)CURLE_BAD_CONTENT_ENCODING)));
  cl_CURLE_LDAP_INVALID_URL=scm_permanent_object(scm_c_define("CURLE_LDAP_INVALID_URL",scm_from_int((int)CURLE_LDAP_INVALID_URL)));
  cl_CURLE_FILESIZE_EXCEEDED=scm_permanent_object(scm_c_define("CURLE_FILESIZE_EXCEEDED",scm_from_int((int)CURLE_FILESIZE_EXCEEDED)));
  cl_CURLE_FTP_SSL_FAILED=scm_permanent_object(scm_c_define("CURLE_FTP_SSL_FAILED",scm_from_int((int)CURLE_FTP_SSL_FAILED)));
  cl_CURLE_SEND_FAIL_REWIND=scm_permanent_object(scm_c_define("CURLE_SEND_FAIL_REWIND",scm_from_int((int)CURLE_SEND_FAIL_REWIND)));
  cl_CURLE_SSL_ENGINE_INITFAILED=scm_permanent_object(scm_c_define("CURLE_SSL_ENGINE_INITFAILED",scm_from_int((int)CURLE_SSL_ENGINE_INITFAILED)));
  cl_CURLE_LOGIN_DENIED=scm_permanent_object(scm_c_define("CURLE_LOGIN_DENIED",scm_from_int((int)CURLE_LOGIN_DENIED)));
  cl_CURLE_TFTP_NOTFOUND=scm_permanent_object(scm_c_define("CURLE_TFTP_NOTFOUND",scm_from_int((int)CURLE_TFTP_NOTFOUND)));
  cl_CURLE_TFTP_PERM=scm_permanent_object(scm_c_define("CURLE_TFTP_PERM",scm_from_int((int)CURLE_TFTP_PERM)));
  cl_CURLE_TFTP_DISKFULL=scm_permanent_object(scm_c_define("CURLE_TFTP_DISKFULL",scm_from_int((int)CURLE_TFTP_DISKFULL)));
  cl_CURLE_TFTP_ILLEGAL=scm_permanent_object(scm_c_define("CURLE_TFTP_ILLEGAL",scm_from_int((int)CURLE_TFTP_ILLEGAL)));
  cl_CURLE_TFTP_UNKNOWNID=scm_permanent_object(scm_c_define("CURLE_TFTP_UNKNOWNID",scm_from_int((int)CURLE_TFTP_UNKNOWNID)));
  cl_CURLE_TFTP_EXISTS=scm_permanent_object(scm_c_define("CURLE_TFTP_EXISTS",scm_from_int((int)CURLE_TFTP_EXISTS)));
  cl_CURLE_TFTP_NOSUCHUSER=scm_permanent_object(scm_c_define("CURLE_TFTP_NOSUCHUSER",scm_from_int((int)CURLE_TFTP_NOSUCHUSER)));
  cl_CURLE_CONV_FAILED=scm_permanent_object(scm_c_define("CURLE_CONV_FAILED",scm_from_int((int)CURLE_CONV_FAILED)));
  cl_CURLE_CONV_REQD=scm_permanent_object(scm_c_define("CURLE_CONV_REQD",scm_from_int((int)CURLE_CONV_REQD)));
  cl_CURLE_SSL_CACERT_BADFILE=scm_permanent_object(scm_c_define("CURLE_SSL_CACERT_BADFILE",scm_from_int((int)CURLE_SSL_CACERT_BADFILE)));
  cl_CURLE_REMOTE_FILE_NOT_FOUND=scm_permanent_object(scm_c_define("CURLE_REMOTE_FILE_NOT_FOUND",scm_from_int((int)CURLE_REMOTE_FILE_NOT_FOUND)));
  cl_CURLE_SSH=scm_permanent_object(scm_c_define("CURLE_SSH",scm_from_int((int)CURLE_SSH)));
  cl_CURLE_SSL_SHUTDOWN_FAILED=scm_permanent_object(scm_c_define("CURLE_SSL_SHUTDOWN_FAILED",scm_from_int((int)CURLE_SSL_SHUTDOWN_FAILED)));

  cl_CURLPROXY_HTTP=scm_permanent_object(scm_c_define("CURLPROXY_HTTP",scm_from_int((int)CURLPROXY_HTTP)));
  cl_CURLPROXY_SOCKS4=scm_permanent_object(scm_c_define("CURLPROXY_SOCKS4",scm_from_int((int)CURLPROXY_SOCKS4)));
  cl_CURLPROXY_SOCKS5=scm_permanent_object(scm_c_define("CURLPROXY_SOCKS5",scm_from_int((int)CURLPROXY_SOCKS5)));

}
  
