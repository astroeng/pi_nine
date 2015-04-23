#include <cmath>
#include <iostream>
#include "compute.h"

using namespace std;

dataOutputType compute_rec(int numeratorArray[], 
                           int denomenatorArray[], 
                           int num_index, 
                           int den_index, 
                           int numerator, 
                           int denomenator)
{
  //cout << "index " << num_index << " : " << den_index << endl;
  
  if (num_index >= 0)
  {
    numerator *= 10;
    numerator += numeratorArray[num_index];
    numeratorArray[num_index]   = USED;
  }
  
  if (den_index >= 0)
  {
    denomenator *= 10;
    denomenator += denomenatorArray[den_index];
    denomenatorArray[den_index] = USED;
  }
  
  dataOutputType outputValue;
  outputValue.value = 1000.0;
  
  for (int num = 0; num < VALUES; num++)
  {
    for (int den = 0; den < VALUES; den++)
    {
      if ((numeratorArray[num] != USED) && (denomenatorArray[den] != USED))
      {
        int numeratorArrayNew[VALUES];
        int denomenatorArrayNew[VALUES];
        
        memcpy(numeratorArrayNew,  numeratorArray,  VALUES*sizeof(int));
        memcpy(denomenatorArrayNew,denomenatorArray,VALUES*sizeof(int));
        
        dataOutputType tryValue = compute_rec(numeratorArrayNew,
                                              denomenatorArrayNew,
                                              num,
                                              den,
                                              numerator,
                                              denomenator);
        
        if (abs(PI - tryValue.value) < abs(PI - outputValue.value))
        {
          outputValue = tryValue;
        }
        
      }
      
    }
    
  }
  
  if (outputValue.value == 1000.0)
  {
    outputValue.value       = (double)numerator / (double)denomenator;
    outputValue.numerator   = numerator;
    outputValue.denomenator = denomenator;
    
    //cout << outputValue.value << " : " << outputValue.numerator << " : " << outputValue.denomenator << endl;

    return outputValue;
  }
  else 
  {
    return outputValue;
  }
  
}