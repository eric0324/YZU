// HugeInteger class definition.
#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H
using namespace std;

class HugeInteger 
{
public:
   HugeInteger( int = 1000 ); // default constructor

   void random(); // randomly generate an integer
   bool zero(); // is zero
   bool equal( HugeInteger ); // is equal to
   bool notEqual( HugeInteger ); // not equal to
   bool greater( HugeInteger ); // greater than
   bool less( HugeInteger ); // less than
   bool greaterEqual( HugeInteger ); // greater than or equal to
   bool lessEqual( HugeInteger ); // less than or equal
   
   // addition operator; HugeInteger + HugeInteger
   HugeInteger add( HugeInteger op2 );

   // subtraction operator; HugeInteger - HugeInteger; return 0 if first value is smaller
   HugeInteger subtract( HugeInteger op2 );

   // multiplication operator; HugeInteger * HugeInteger
   HugeInteger multiply( HugeInteger op2 );

   // division operator; HugeInteger / HugeInteger
   HugeInteger divide( HugeInteger op2 );

   // modulus operator; HugeInteger % HugeInteger
	HugeInteger modulus( HugeInteger op2 );

   void output();
private:
   int size;              // the number of digits of the integer
   short integer[ 1000 ]; // used to store a positive integer as large as 1000 digits
   void divideByTen();
}; // end class HugeInteger

#endif