// Member-function definitions for class Vector.
#include <iostream>
#include <iomanip>
#include "Vector.h" // include definition of class Vector 
using namespace std;

// default constructor
Vector::Vector( unsigned int n, const int val )
{
   if( n > 0 )
   {
      ptr = new int[ n ];

      for ( unsigned int i = 0; i < n; i++ )
         ptr[ i ] = val;

      size = n;
      capacity = n;
   }
   else
   {
      size = 0;
      capacity = 0;
      ptr = new int[ 0 ];
   }
} // end Vector constructor

// destructor
Vector::~Vector()
{
   delete [] ptr;
} // end destructor

int* Vector::begin()
{
   return ptr;
}

int* Vector::end()
{
   return ptr + size;
}

unsigned int Vector::getSize() const
{
   return size;
}

unsigned int Vector::getCapacity() const
{
   return capacity;
}

bool Vector::empty() const
{
   return ( size == 0 );
}

int& Vector::front()
{
   return ptr[0];
}

int& Vector::back()
{
   return ptr[ size - 1 ];
}

void Vector::pop_back()
{
   size--;
}

void Vector::clear()
{
   size = 0;
}

void Vector::display()
{
   for( unsigned int i = 0; i < size; i++ )
   {
      cout << setw(3) << ptr[ i ];
      if( i % 10 == 9 || i == size - 1 )
         cout << endl;
   }
   cout << endl;
}