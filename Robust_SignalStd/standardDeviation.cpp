#include "standardDeviation.hpp"
void sig_std(double * pSig_src_arr, uint32_t blockSize, double *pResult){

double sum = 0.0;
double sumOfSquares = 0.0;
double in;

uint32_t blkCnt;

double meanOfSquares, mean, squareOfMean;
double squareOfSum = 0.0;

double var;

if(blockSize == 1){
    *pResult = 0;
    return;
}

blkCnt = blockSize>>2;

while(blkCnt>0){
//perform this operation 4 times
    in = *pSig_src_arr++;
    sum+= in;
    sumOfSquares += in*in;
//perform this operation 4 times
    in = *pSig_src_arr++;
    sum+= in;
    sumOfSquares += in*in;
//perform this operation 4 times
    in = *pSig_src_arr++;
    sum+= in;
    sumOfSquares += in*in;
//perform this operation 4 times
    in = *pSig_src_arr++;
    sum+= in;
    sumOfSquares += in*in;

    blkCnt--;
}

blkCnt = blockSize % 0x4;

while(blkCnt>0){
//perform this operation 4 times
    in = *pSig_src_arr++;
    sum+= in;
    sumOfSquares += in*in;

    blkCnt--;
}

    meanOfSquares = sumOfSquares / ((double)blockSize-1.0);
    mean = sum/(double) blockSize;

    squareOfMean = (mean*mean) * ((double)blockSize/(double)(blockSize-1.0));

    *pResult = sqrt((meanOfSquares-squareOfMean));
}

