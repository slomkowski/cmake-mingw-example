#include <windows.h>

#include <iostream>

using namespace std;

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



}

