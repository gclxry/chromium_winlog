# chromium_winlog
a logging library for windows from chromium.

更多信息查看我的博客 http://blog.gclxry.com

这个log是从开源的chromium工程中抽取出来的。
支持的特性：
* 支持输出log到文件，系统调试器
* 支持输出不同等级log
* 支持错误回调函数
* 支持惰性输出，支持条件输出，支持仅在debug模式生效
* 支持同时输出当前的GetLastError信息
* 支持发生错误时的栈回溯
* 支持线程安全

## 3分钟教程

### 初始化

使用log库之前需要调用logging::InitLogging函数初始化一次。

调用logging::SetLogItems设置输出每条log包含的的信息，比如进程id，线程id，时间戳，精确时间。

### log等级

log分4个等级。INFO，WARNING，ERROR，FATAL。
FATAL等级的log会触发一个断点。

### 输出log

输出log都是通过一些宏来输出，类似std::cout的用法。

	  LOG(INFO) << "log INFO";
	  LOG(WARNING) << "log WARNING";
	  LOG(ERROR) << "log ERROR";
	  LOG(FATAL) << "log FATAL";
	  
_IF后缀的是条件输出log

	LOG_IF(INFO, num_cookies > 10) << "Got lots of cookies";

D前缀的是只在debug模式下生效
  
	DLOG(INFO) << "Found cookies";
	DLOG_IF(INFO, num_cookies > 10) << "Got lots of cookies";

P前缀的是输出log之后会附加上GetLastError信息

	PLOG(ERROR) << "Couldn't do foo";
	DPLOG(ERROR) << "Couldn't do foo";
	DPLOG_IF(ERROR, cond) << "Couldn't do foo";
