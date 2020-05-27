/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2018 The PHP Group                                |
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

/* $Id$ */

#ifndef PHP_F_REDIS_GET_CONNECTED_H
#define PHP_F_REDIS_GET_CONNECTED_H

extern zend_module_entry f_redis_get_connected_module_entry;
#define phpext_f_redis_get_connected_ptr &f_redis_get_connected_module_entry

#define PHP_F_REDIS_GET_CONNECTED_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_F_REDIS_GET_CONNECTED_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_F_REDIS_GET_CONNECTED_API __attribute__ ((visibility("default")))
#else
#	define PHP_F_REDIS_GET_CONNECTED_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/*
  	Declare any global variables you may need between the BEGIN
	and END macros here:

ZEND_BEGIN_MODULE_GLOBALS(f_redis_get_connected)
	zend_long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(f_redis_get_connected)
*/

ZEND_BEGIN_MODULE_GLOBALS(f_redis_get_connected)
  zend_long  redis_port;
  char *redis_host;
ZEND_END_MODULE_GLOBALS(f_redis_get_connected)

/* Always refer to the globals in your function as F_REDIS_GET_CONNECTED_G(variable).
   You are encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/
#define F_REDIS_GET_CONNECTED_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(f_redis_get_connected, v)

#if defined(ZTS) && defined(COMPILE_DL_F_REDIS_GET_CONNECTED)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif	/* PHP_F_REDIS_GET_CONNECTED_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
