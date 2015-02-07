// chromium_winlog_demo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include "../src/logging.h"

int _tmain(int argc, _TCHAR* argv[])
{
  logging::LoggingSettings settings;
  settings.logging_dest = logging::LOG_TO_SYSTEM_DEBUG_LOG;
  logging::InitLogging(settings);

  //log是否记录进程id,线程id,时间戳，精确时间
  logging::SetLogItems(true, true, false, false);

  LOG(INFO) << "INFO";
  LOG(WARNING) << "WARNING";
  LOG(ERROR) << "ERROR";

  LOG_IF(INFO, true) << "LOG_IF INFO";
  LOG_IF(WARNING, false) << "LOG_IF WARNING";
  LOG_IF(ERROR, true) << "LOG_IF ERROR";

  system("pause");
	return 0;
}

