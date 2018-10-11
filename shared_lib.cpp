#define SHARED_LIB_SOURCE

#include "shared_lib.h"

#include <windows.h>

#include <iostream>

extern "C" BOOL APIENTRY DllMain(HINSTANCE hInst, DWORD reason, LPVOID reserved) {

    switch (reason) {
        case DLL_PROCESS_ATTACH:
            std::cout << "DLL loaded" << std::endl;
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

extern "C" PUBLIC_FUNCTION int multiplyTwoNumbers(int a, int b) {
    auto result = a * b;
    std::cout << "Multiplying " << a << " and " << b << " giving " << result << std::endl;
    return result;
}
