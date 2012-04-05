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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_hellovigossguard.h"
#include "string.h"

/* If you declare any globals in php_hellovigossguard.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(hellovigossguard)
*/

/* True global resources - no need for thread safety here */
static int le_hellovigossguard;

char * key = "asdf";
/* {{{ hellovigossguard_functions[]
 *
 * Every user visible function must have an entry in hellovigossguard_functions[].
 */
const zend_function_entry hellovigossguard_functions[] = {
	PHP_FE(confirm_hellovigossguard_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE(encode,	NULL)		/* For testing, remove later. */
	PHP_FE(decode,	NULL)		/* For testing, remove later. */
	PHP_FE(run,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in hellovigossguard_functions[] */
};
/* }}} */

/* {{{ hellovigossguard_module_entry
 */
zend_module_entry hellovigossguard_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"hellovigossguard",
	hellovigossguard_functions,
	PHP_MINIT(hellovigossguard),
	PHP_MSHUTDOWN(hellovigossguard),
	PHP_RINIT(hellovigossguard),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(hellovigossguard),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(hellovigossguard),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_HELLOVIGOSSGUARD
ZEND_GET_MODULE(hellovigossguard)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("hellovigossguard.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_hellovigossguard_globals, hellovigossguard_globals)
    STD_PHP_INI_ENTRY("hellovigossguard.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_hellovigossguard_globals, hellovigossguard_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_hellovigossguard_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_hellovigossguard_init_globals(zend_hellovigossguard_globals *hellovigossguard_globals)
{
	hellovigossguard_globals->global_value = 0;
	hellovigossguard_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(hellovigossguard)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(hellovigossguard)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(hellovigossguard)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(hellovigossguard)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(hellovigossguard)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "hellovigossguard support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* Remove the following function when you have succesfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_hellovigossguard_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_hellovigossguard_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "hellovigossguard", arg);
	RETURN_STRINGL(strg, len, 0);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/
PHP_FUNCTION(encode){
	long key_len = strlen(key);
	char * code, * encode_code;
	long code_len;
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &code, &code_len) == FAILURE){
		return;
	}
	encode_code = encode(code, code_len, key, key_len);
	RETURN_STRING(encode_code, 0);
}
PHP_FUNCTION(decode){
	long key_len = strlen(key);
	char * code, * decode_code;
	long code_len;
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &code, &code_len) == FAILURE){
		return;
	}
	decode_code = decode(code, code_len, key, key_len);
	RETURN_STRING(decode_code, 0);
}
PHP_FUNCTION(run){
	char * en_base64_code;
	long en_base64_code_len;
	char * decode_code;
	long key_len = strlen(key);
	char * eval_code;
	char * str_name;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &en_base64_code, &en_base64_code_len) == FAILURE){
		return;
	}

	str_name = zend_make_compiled_string_description("hellovigoss" TSRMLS_CC);
	decode_code = decode(en_base64_code, en_base64_code_len, key, key_len);
	spprintf(&eval_code, 0, " ?>%s<?php ", decode_code);
	free(decode_code);
	if(zend_eval_string(eval_code, NULL, str_name) == FAILURE){
		efree(str_name);
		efree(eval_code);
		php_error_docref(NULL TSRMLS_CC, E_RECOVERABLE_ERROR, "Please make sure '<?php' end with '?>'", PHP_EOL);
		RETURN_FALSE;
	}
	efree(str_name);
	efree(eval_code);
	RETURN_TRUE;
	
}
inline char * encode(char * code, long code_len, char* key, long key_len){
	char * code_encode;
	int i;
	code_encode = strdup(code);
	long offset = 0, ret_len;
	for(i =0; i<code_len; i++){
		if(offset == key_len){
			offset = 0;
		}
		* (code_encode + i) = * (code + i) ^ * (key + offset);
		offset ++;
	}
	return php_base64_encode(code_encode, code_len, &ret_len);
}
inline char * decode(char * code,long code_len, char* key, long key_len){
	char * code_decode;
	int i;
	code_decode = strdup(code);
	long offset = 0, ret_len;
	zend_bool strict = 0;
	char * nobase_code = php_base64_decode_ex((unsigned char*)code, code_len, &ret_len, strict);
	for(i =0; i<ret_len; i++){
		if(offset == key_len){
			offset = 0;
		}
		* (code_decode + i) = * (nobase_code + i) ^ * (key + offset);
		offset ++;
	}
	* (code_decode + i) = '\0';
	return code_decode;
}
/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
