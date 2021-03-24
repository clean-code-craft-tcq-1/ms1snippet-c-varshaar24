#include "sensor-validate.h"

int DiffIsLessThanOrEqualToMaxDelta(double value, double nextValue, double maxDelta)
{ 
  return (nextValue - value <= maxDelta);
}

int CheckSOCReadings(double* values, int numOfValues,double maxDelta)
{
  int lastButOneIndex = numOfValues - 1;
  
  for(int i = 0; i < lastButOneIndex; i++)
  {
    if(DiffIsLessThanOrEqualToMaxDelta(values[i], values[i + 1], maxDelta))
    {
      return 0;
    }
  }
  
  
  return 1;
}

int validateSOCreadings(double* values, int numOfValues,double maxDelta)
{
  int RetVal=0;
  if(values == 0)
  {
    return 1;
  }
  
  RetVal = CheckSOCReadings(values, numOfValues,maxDelta);
 
  return RetVal;
}



