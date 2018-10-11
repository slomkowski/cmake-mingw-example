#include <windows.h>

#include <iostream>

using namespace std;

extern "C" typedef __stdcall int (*multiplyTwoNumbersFunc)(int a, int b);

/*
 * This code demonstrates the loading of DLL library in runtime.
 */
int main(int argc, char *argv[]) {

    HMODULE hLib = LoadLibrary("shared_lib.dll");

    if (hLib == nullptr) {
        throw runtime_error("Error: load library ");
    }

    auto GetProcAddressAndCheck = [&](LPCSTR procName) {
        auto farProc = GetProcAddress(hLib, procName);
        if (farProc == nullptr) {
            throw runtime_error(string("Error: cannot find procedure ") + procName);
        }
        return farProc;
    };

    auto multiplyTwoNumbersPtr = (multiplyTwoNumbersFunc) GetProcAddressAndCheck("multiplyTwoNumbers");

    auto result = multiplyTwoNumbersPtr(34, 11);

    MessageBox(nullptr, to_string(result).c_str(), "MessageBox test", MB_ICONINFORMATION | MB_OK);
}

