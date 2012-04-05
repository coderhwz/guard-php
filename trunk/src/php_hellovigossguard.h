/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id: header 321634 2012-01-01 13:15:04Z felipe $ */

#ifndef PHP_HELLOVIGOSSGUARD_H
#define PHP_HELLOVIGOSSGUARD_H

extern zend_module_entry hellovigossguard_module_entry;
#define phpext_hellovigossguard_ptr &hellovigossguard_module_entry

#ifdef PHP_WIN32
#	define PHP_HELLOVIGOSSGUARD_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_HELLOVIGOSSGUARD_API __attribute__ ((visibility("default")))
#else
#	define PHP_HELLOVIGOSSGUARD_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(hellovigossguard);
PHP_MSHUTDOWN_FUNCTION(hellovigossguard);
PHP_RINIT_FUNCTION(hellovigossguard);
PHP_RSHUTDOWN_FUNCTION(hellovigossguard);
PHP_MINFO_FUNCTION(hellovigossguard);

PHP_FUNCTION(confirm_hellovigossguard_compiled);	/* For testing, remove later. */
PHP_FUNCTION(encode);
PHP_FUNCTION(decode);
PHP_FUNCTION(run);

char * encode(char * code, long code_len, char * key, long key_len);
char * decode(char * code, long code_len, char * key, long key_len);

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(hellovigossguard)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(hellovigossguard)
*/

/* In every utility function you add that needs to use variables 
   in php_hellovigossguard_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as HELLOVIGOSSGUARD_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define HELLOVIGOSSGUARD_G(v) TSRMG(hellovigossguard_globals_id, zend_hellovigossguard_globals *, v)
#else
#define HELLOVIGOSSGUARD_G(v) (hellovigossguard_globals.v)
#endif

#endif	/* PHP_HELLOVIGOSSGUARD_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
