#include <cmath>
#include <iostream>
#include "compute.h"

using namespace std;

int numeratorArray[] = {1,2,3,4,5,6,7,8,9,0};
int denomenatorArray[] = {1,2,3,4,5,6,7,8,9,0};


int main()
{
  
  int numerator = 0;
  int denomenator = 0;
  
  dataOutputType outputValue;
  outputValue.value = 1000.0;

  
  int numeratorArrayNew[VALUES];
  int denomenatorArrayNew[VALUES];
  
  memcpy(numeratorArrayNew,  numeratorArray,  VALUES*sizeof(int));
  memcpy(denomenatorArrayNew,denomenatorArray,VALUES*sizeof(int));
  
  outputValue = compute_rec(numeratorArrayNew,
                            denomenatorArrayNew,
                            -1,
                            -1,
                            numerator,
                            denomenator);
  
  cout << outputValue.value << " : " << outputValue.numerator << " : " << outputValue.denomenator << endl;

}