#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SHARED_LIB_SOURCE
#define PUBLIC_FUNCTION __stdcall  __declspec(dllexport)
#else
#define PUBLIC_FUNCTION __stdcall __declspec(dllimport)
#endif

PUBLIC_FUNCTION int multiplyTwoNumbers(int a, int b);

#ifdef __cplusplus
}
#endif
