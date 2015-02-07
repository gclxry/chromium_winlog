#include "stdafx.h"
#include <stdarg.h>
#include "chromium_logging_util.h"


std::string remove_prefix(const std::string s, const std::string::size_type n)
{
  std::string sRet = s.substr(n, s.size() - n);
  return sRet;
}

std::string remove_suffix(const std::string s, const std::string::size_type n)
{
  return s.substr(0, s.size() - n);
}


std::string WideToUTF8(const std::wstring& wide)
{
  std::string ret;
  return ret;
}


namespace base{
  namespace debug{
    void Alias(const void* var) {
    }

    void BreakDebugger() {
      __debugbreak();
#if defined(NDEBUG)
      _exit(1);
#endif
    }

  }
}

namespace win_string_convert{
  std::string WStringTOString(const std::wstring str, const DWORD dwType)
  {
    int nMultiByteLenght = WideCharToMultiByte(dwType, 0, str.c_str(), -1, NULL, 0, NULL, NULL);
    char* pMultiByteBuffer = new char[nMultiByteLenght];
    nMultiByteLenght = WideCharToMultiByte(dwType, 0, str.c_str(), -1, pMultiByteBuffer, nMultiByteLenght, NULL, NULL);
    std::string sRet = pMultiByteBuffer;
    delete[] pMultiByteBuffer;
    return sRet;
  }
  std::wstring StringToWString(const std::string str, const DWORD dwType)
  {
    int nWideCharLenght = MultiByteToWideChar(dwType, 0, str.c_str(), -1, NULL, 0);
    wchar_t* pWideCharBuffer = new wchar_t[nWideCharLenght];
    nWideCharLenght = MultiByteToWideChar(dwType, 0, str.c_str(), -1, pWideCharBuffer, nWideCharLenght);
    std::wstring sRet = pWideCharBuffer;
    delete[] pWideCharBuffer;
    return sRet;
  }

  std::string AnsiToUtf8(const std::string str)
  {
    std::wstring temp = StringToWString(str, CP_ACP);
    return WStringTOString(temp, CP_UTF8);
  }
  std::string Utf8ToAnsi(const std::string str)
  {
    std::wstring temp = StringToWString(str, CP_UTF8);
    return WStringTOString(temp, CP_ACP);
  }

  std::wstring UTF8ToWide(const std::string& s)
  {
    return StringToWString(Utf8ToAnsi(s));
  }

  std::string WideToUTF8(const std::wstring& wide)
  {
    std::string temp = WStringTOString(wide);
    return AnsiToUtf8(temp);
  }
}
