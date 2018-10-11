#include "shared_lib.h"

#include <windows.h>

#include <iostream>

extern "C" BOOL APIENTRY DllMain(HINSTANCE hInst, DWORD reason, LPVOID reserved) {

    switch (reason) {
        case DLL_PROCESS_ATTACH:
            break;

        case DLL_PROCESS_DETACH:
            break;

        case DLL_THREAD_ATTACH:
            break;

        case DLL_THREAD_DETACH:
            break;
    }

    return TRUE;
}

extern "C" __stdcall __declspec(dllexport) int multiplyTwoNumbers(int a, int b) {
    auto result = a + b;
    std::cout << "Multiplying " << a << " and " << b << " giving " << result << std::endl;
    return result;
}
