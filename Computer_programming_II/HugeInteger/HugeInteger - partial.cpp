// Member-function definitions for class HugeInteger.
#include <iostream>
#include "HugeInteger.h" // include definition of class HugeInteger 
using namespace std;

// default constructor
HugeInteger::HugeInteger( int s )
{
   size = ( s > 0 && s <= 1000 ) ? s : 1000;
   // initialize array to zero
   for ( int i = 0; i < size; i++ )
      integer[ i ] = 0;
} // end HugeInteger default constructor

// randomly generate an integer
void HugeInteger::random()
{
   integer[ size - 1 ] = 1 + rand() % 9;
   for ( int i = 0; i < size - 1; i++ )
      integer[ i ] = rand() % 10;
} // end function random

// function that tests if a HugeInteger is zero
bool HugeInteger::zero()
{
   if( size == 0 )
      return true;

   for ( int i = 0; i < size; i++ )
      if ( integer[ i ] != 0 )
         return false;
         
   return true;
} // end function zero

// addition operator; HugeInteger + HugeInteger
HugeInteger HugeInteger::add( HugeInteger op2 )
{
   int sumSize = ( size >= op2.size ) ? size + 1 : op2.size + 1;
   HugeInteger sum( sumSize );

   for ( int i = 0; i < size; i++ )
      sum.integer[ i ] = integer[ i ];

   for ( int i = 0; i < op2.size; i++ )
      sum.integer[ i ] += op2.integer[ i ];

   for ( int i = 0; i < sum.size - 1; i++ ) 
      if ( sum.integer[ i ] > 9 ) // determine whether to carry a 1
      {
         sum.integer[ i ] -= 10; // reduce to 0-9
         sum.integer[ i + 1 ]++;
      }

	if( sum.integer[ sum.size - 1 ] == 0 )
		sum.size--;

   return sum;
} // end function add

// overloaded output operator
void HugeInteger::output()
{
   int k;
   if( size == 0 )
      cout << 0;
   else
   {
      for( k = size - 1; k >= 0; k-- )
         if( integer[ k ] != 0 )
            break;

      if( k == -1 )
         cout << 0;
      else
         for( int i = k; i >= 0; i-- ) // display the HugeInteger
            cout << integer[ i ];
   }
} // end function output

void HugeInteger::divideByTen()
{
   for( int i = 1; i < size; i++ )
      integer[ i - 1 ] = integer[ i ];
   integer[ size ] = 0;
   size--;
} // end function divideByTen