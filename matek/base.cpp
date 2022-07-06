#include "base.h"

unsigned int factorial(unsigned int num, unsigned int dividedBy)
{
    unsigned long int l_Result = 1;
    for (num; num > dividedBy; num--)
    {
        l_Result *= num;
    }
    return l_Result;
}

unsigned int nCr(unsigned int n, unsigned int r)
{
    if (n < r)
        return 0;
    return factorial(n, (n-r)) / factorial(r);
}

double division(double a, double b)
{
    return a / b;
}

double roundToDecimal(double numToRound, int decToRound)
{
    numToRound *= pow(10, decToRound);
    numToRound += 0.5f;
    numToRound = (int)numToRound;
    numToRound = (double)numToRound / pow(10, decToRound);
    return numToRound;
}
