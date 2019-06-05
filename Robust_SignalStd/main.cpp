#include <iostream>
#include "standardDeviation.hpp"
#define BLOCKSIZE 320
using namespace std;

extern double InputSignal_f32_1kHz_15kHz[320];

double standardDeviation;
int main()
{
    sig_std(InputSignal_f32_1kHz_15kHz,BLOCKSIZE,&standardDeviation);
    cout << "Hello world the standard Deviation is: " << standardDeviation << endl;
    return 0;
}
