#define USED 11
#define VALUES 8

#define PI 3.14159265359

/*
 *
 */

struct dataOutput
{
  double value;
  int numerator;
  int denomenator;
} typedef dataOutputType;

/*
 *
 */

dataOutputType compute_rec(int numeratorArray[], 
                           int denomenatorArray[], 
                           int num_index, 
                           int den_index, 
                           int numerator, 
                           int denomenator);
