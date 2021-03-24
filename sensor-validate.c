#include "sensor-validate.h"

int DiffIsLessThanOrEqualToMaxDelta(double value, double nextValue, double maxDelta)
{ 
  int ReturnVal;
  ReturnVal = (nextValue - value > maxDelta) ? 0 : 1;
  return ReturnVal;
}

int validateSOCreadings(double* values, int numOfValues,double maxDelta)
{
  int lastButOneIndex = numOfValues - 1;
  if(values == 0)
  {
    return 1;
  }
  
  for(int i = 0; i < lastButOneIndex; i++)
  {
    if(DiffIsLessThanOrEqualToMaxDelta(values[i], values[i + 1], maxDelta))
    {
      return 0;
    }
  }
  
  return 1;
}

