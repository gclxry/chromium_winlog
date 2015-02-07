#pragma once


#include <stdint.h>  // For intptr_t.
#include <vector>
#include <string>
#include <windows.h>

//


// The arraysize(arr) macro returns the # of elements in an array arr.
// The expression is a compile-time constant, and therefore can be
// used in defining new arrays, for example.  If you use arraysize on
// a pointer by mistake, you will get a compile-time error.
//
// One caveat is that arraysize() doesn't accept any array of an
// anonymous type or a type defined inside a function.  In these rare
// cases, you have to use the unsafe ARRAYSIZE_UNSAFE() macro below.  This is
// due to a limitation in C++'s template system.  The limitation might
// eventually be removed, but it hasn't happened yet.

// This template function declaration is used in defining arraysize.
// Note that the function doesn't need an implementation, as we only
// use its type.
template <typename T, size_t N>
char(&ArraySizeHelper(T(&array)[N]))[N];

// That gcc wants both of these prototypes seems mysterious. VC, for
// its part, can't decide which to use (another mystery). Matching of
// template overloads: the final frontier.
#ifndef _MSC_VER
template <typename T, size_t N>
char(&ArraySizeHelper(const T(&array)[N]))[N];
#endif

#define arraysize(array) (sizeof(ArraySizeHelper(array)))


std::string remove_prefix(const std::string s, const std::string::size_type n);
std::string remove_suffix(const std::string s, const std::string::size_type n);

template<typename T>
inline void ignore_result(const T&) {
}

namespace base{
  namespace debug{
    void Alias(const void* var);

    // Break into the debugger, assumes a debugger is present.
    void BreakDebugger();

    bool IsDebugUISuppressed();
  }
}

#define HANDLE_EINTR(x) (x)
#define IGNORE_EINTR(x) (x)

namespace win_string_convert{
  std::string WStringTOString(const std::wstring str, const DWORD dwType = CP_ACP);
  std::wstring StringToWString(const std::string str, const DWORD dwType = CP_ACP);
  std::string AnsiToUtf8(const std::string str);
  std::string Utf8ToAnsi(const std::string str);
  std::wstring UTF8ToWide(const std::string& s);
  std::string WideToUTF8(const std::wstring& wide);
}