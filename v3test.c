#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "v3math.h"

int main() 
{
  //initialize test loop variables
  int functionNum = 0;
  float tolerance = 0.05;
  int testNum;
  float angle;
  float length;
  float dot;
  float scale;

  printf( "Running tests for v3math library\n\n" );
 
  while( functionNum < 11 )
  {
    testNum = 1;

    while( testNum < 6 )
    {
      //creates 3 random values for a from 1-30
      float aVal1 = rand() % 30 + 1;
      float aVal2 = rand() % 30 + 1;
      float aVal3 = rand() % 30 + 1;

      //creates 3 random values for b from 1-30
      float bVal1 = rand() % 30 + 1;
      float bVal2 = rand() % 30 + 1;
      float bVal3 = rand() % 30 + 1;

      //initialize destination to 0
      float testDest[3] = {0, 0, 0};
	
      //initialize a and b with random values
      float a[3] = {aVal1, aVal2, aVal3};
      float b[3] = {bVal1, bVal2, bVal3};

      switch( functionNum )
      {

	case 0:
	  v3_from_points( testDest, a, b );

	  if( (testDest[0] == abs(b[0] - a[0])) &&
		(testDest[1] == abs(b[1] - a[1])) &&
		(testDest[2] == abs(b[2] - b[2])))
	  {
	    printf( "Test %d passed for v3_from_points\n", testNum );
	  }
	  else
	  {
	    printf( "Test %d failed for v3_from_points\n", testNum );
	  }
	  break;

	case 1:
	  v3_add( testDest, a, b );

	  if( testDest[0] == a[0] + b[0] &&
		testDest[1] == a[1] + b[1] &&
		testDest[2] == a[2] + b[2])
	  {
	    printf( "Test %d passed for v3_add\n", testNum );
	  }
	  else
	  {
	    printf( "Test %d failed for v3_add\n", testNum );
	  }
	  break;

	case 2:
	  v3_subtract( testDest, a, b );

	  if( testDest[0] == a[0] - b[0] &&
		testDest[1] == a[1] - b[1] &&
		testDest[2] == a[2] - b[2])
	  {
	    printf( "Test %d passed for v3_subtract\n", testNum );
	  }
	  else
	  {
	    printf( "Test %d failed for v3_subtract\n", testNum );
	  }
	  break;

	case 3:
	  dot = v3_dot_product( a, b );

	  if( dot == ((a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]))) 
	  {
	    printf( "Test %d passed for v3_dot_product\n", testNum );
	  }
	  else
	  {
	    printf( "Test %d failed for v3_dot_product\n", testNum );
	  }
	  break;

	case 4:
	  v3_cross_product( testDest, a, b );

	  if( testDest[0] == (a[1] * b[2]) - (a[2] * b[1]) &&
		testDest[1] == (a[2] * b[0]) - (a[0] * b[2]) &&
		testDest[2] == (a[0] * b[1]) - (a[1] * b[0]))
	  {
	    printf( "Test %d passed for v3_cross_product\n", testNum );
	  }
	  else
	  {
	    printf( "Test %d failed for v3_cross_product\n", testNum );
	  }
	  break;

	case 5:
	  scale = rand() % 20 + 1;
	  v3_scale( testDest, scale );

	  if( (testDest[0] == testDest[0] * scale) &&
		(testDest[1] == testDest[1] * scale) &&
		(testDest[2] == testDest[2] * scale))
	  {
	    printf( "Test %d passed for v3_scale\n", testNum );
	  }
	  else
	  {
	    printf( "Test %d failed for v3_scale\n", testNum );
	  }
	  break;

	case 6:
	  angle = v3_angle( a, b );

	  if( angle == (acosf(v3_dot_product(a,b) / (v3_length(a) * v3_length(b)))))
	  {
	    printf( "Test %d passed for v3_angle\n", testNum );
	  }
	  else
	  {
	    printf( "Test %d failed for v3_angle\n", testNum );
	  }
	  break;

	case 7:
	  angle = v3_angle_quick( a, b );

	  if( angle == (v3_dot_product(a,b) / (v3_length(a) * v3_length(b))))
	  {
	    printf( "Test %d passed for v3_angle_quick\n", testNum );
	  }
	  else
	  {
	    printf( "Test %d failed for v3_angle_quick\n", testNum );
	  }
	  break;

	case 8:
	  v3_reflect( testDest, a, b );

	  if( testDest[0] == (2 * v3_dot_product(a, b) * b[0] - a[0]) &&
		testDest[1] == (2 * v3_dot_product(a, b) * b[1] - a[1]) &&
		testDest[2] == 2 * v3_dot_product(a, b) * b[2] - a[2])
	  {
	    printf( "Test %d passed for v3_reflect\n", testNum );
	  }
	  else
	  {
	    printf( "Test %d failed for v3_reflect\n", testNum );
	  }
	  break;

	case 9:
	  length = v3_length( a );

	  if( length == (sqrt(pow(a[0],2) + pow(a[1],2) + pow(a[2],2))))
	  {
	    printf( "Test %d passed for v3_length\n", testNum );
	  }
	  else
	  {
	    printf( "Test %d failed for v3_length\n", testNum );
	  }
	  break;

	case 10:
	  v3_normalize( testDest, a );
	  length = v3_length(a);

	  if( testDest[0] == a[0] / length &&
		testDest[1] == a[1] / length &&
		testDest[2] == a[2] / length)
	  {
	    printf( "Test %d passed for v3_normalize\n", testNum );
	  }
	  else
	  {
	    printf( "Test %d failed for v3_normalize\n", testNum );
	  }
	  break;
      }

      testNum++;
    }

    printf( "\n" );
    functionNum++;
  }

  printf("All tests complete. Exiting program\n");
}
