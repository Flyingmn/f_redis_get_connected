# PHP-Redis长连接 f_redis_get_connected

redis: get test 

## 依赖
[hiredis](https://github.com/redis/hiredis)

## 初始化

下载PHP7源码ext
```shell
cd ext
```

编辑文件 f_redis_get_connected.def 内容如src/f_redis_get_connected.def
```shell
vim f_redis_get_connected.def
./ext_skel --extname=f_redis_get_connected --proto=f_redis_get_connected.def
```

## 编译配置
```shell
cd f_redis_get_connected  
vim config.m4
```
去掉 PHP_ARG_WITH 和 [  --with-f_redis_get_connected 前面的dnl 在文件底部添加下面两行，内容如src/config.m4
```m4
PHP_ADD_LIBRARY_WITH_PATH(hiredis, /usr/local/lib/, F_REDIS_GET_CONNECTED_SHARED_LIBADD)  
PHP_SUBST(F_REDIS_GET_CONNECTED_SHARED_LIBADD)  
```

## 功能实现  
实现函数 PHP_FUNCTION(f_redis_get_connected) 代码如 src/f_redis_get_connected.c  
```
vim f_redis_get_connected.c
```
## 添加配置
1、php_f_redis_get_connected.h中添加如下内容
```
ZEND_BEGIN_MODULE_GLOBALS(f_redis_get_connected)
  zend_long  redis_port;
  char *redis_host;
ZEND_END_MODULE_GLOBALS(f_redis_get_connected)
```
2、f_redis_get_connected.c中添加如下内容
```
ZEND_DECLARE_MODULE_GLOBALS(f_redis_get_connected)
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("f_redis_get_connected.redis_port",      "6379", PHP_INI_ALL, OnUpdateLong, redis_port, zend_f_redis_get_connected_globals, f_redis_get_connected_globals)
    STD_PHP_INI_ENTRY("f_redis_get_connected.redis_host", "127.0.0.1", PHP_INI_ALL, OnUpdateString, redis_host, zend_f_redis_get_connected_globals, f_redis_get_connected_globals)
PHP_INI_END()
```
3、php.ini中添加如下内容
```
extension=f_redis_get_connected.so
;;;;;;;;;;;;;;;;;;;
; Module Settings ;
;;;;;;;;;;;;;;;;;;;

[F_redis_get_connected]
f_redis_get_connected.redis_host = "127.0.0.1"
f_redis_get_connected.redis_port = 6379
```
4、f_redis_get_connected.c中获取配置方法如下
```
F_REDIS_GET_CONNECTED_G(redis_host)
```
## 编译、安装

```shell
PHP7/bin/phpize  
./configure --with-php-config=PHP7/bin/php-config  
./make && make install  
```
## 运行PHP 
```php
print_r(f_redis_get_connected('0', 'test'));
```

