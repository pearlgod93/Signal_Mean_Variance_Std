#include <iostream>
#include "rms.hpp"
#define BLOCKSIZE 320

using namespace std;
extern double InputSignal_f32_1kHz_15kHz[320];

double rms_value;
int main()
{
    sig_rms(InputSignal_f32_1kHz_15kHz, BLOCKSIZE, &rms_value);
    cout << rms_value << endl;
    return 0;
}
