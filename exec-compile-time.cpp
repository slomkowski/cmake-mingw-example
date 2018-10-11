#include "shared_lib.h"

#include <windows.h>
#include <zlib.h>

#include <iostream>

/*
 * This code demonstrates the usage of shared library as compile-time dependency.
 */
int main(int argc, char *argv[]) {

    // do some zlib test, it doesn't make any sense just uses functions from zlib library
    unsigned char inBuffer[30], outBuffer[30];
    z_stream strm;
    strm.zalloc = nullptr;
    strm.zfree = nullptr;
    strm.next_in = inBuffer;
    strm.avail_in = 10;
    strm.next_out = outBuffer;
    strm.avail_out = 10;
    deflateInit(&strm, Z_BEST_COMPRESSION);

    auto result = multiplyTwoNumbers(34, 11);

    MessageBox(nullptr, std::to_string(result).c_str(), "MessageBox test", MB_ICONINFORMATION | MB_OK);
}
