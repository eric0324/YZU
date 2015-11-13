// HugeInteger test program.
#include <iostream>
#include <ctime>
#include "HugeInteger.h" // include definition of class HugeInteger
using namespace std;

int main()
{
   int seed;
   cout << "Enter seed: ";
   cin >> seed;
   srand( seed );
   cout << endl;

   int length1;
   int length2;
   cout << "Enter the lengths of two huge integers: ";
   cin >> length1 >> length2;

   HugeInteger n1( length1 );
   HugeInteger n2( length2 );

   // tests for zero at n1
   if ( n1.zero() )
   {
      cout << "\nn1 contains ";
      n1.output();
      cout << "\n\n";
   }

   n1.random();

   // checks for equality between n1 and n1 
   if ( n1.equal( n1 ) )
   { 
      n1.output();
      cout << " == ";
      n1.output();
      cout << "\n\n";
   }

   n2.random();

   // checks for equality between n1 and n2 
   if ( n1.equal( n2 ) )
   { 
      n1.output();
      cout << " == ";
      n2.output();
      cout << "\n\n";
   }      

   // checks for inequality between n1 and n1
   if ( n1.notEqual( n1 ) )
   {
      n1.output();
      cout << " != ";
      n1.output();
      cout << "\n\n";
   }

   // checks for inequality between n1 and n2
   if ( n1.notEqual( n2 ) )
   {
      n1.output();
      cout << " != ";
      n2.output();
      cout << "\n\n";
   }

   // tests for greater number between n1 and n1 
   if ( n1.greater( n1 ) )
   {
      n1.output();
      cout << " > ";
      n1.output();
      cout << "\n\n";
   }

   // tests for greater number between n1 and n2 
   if ( n1.greater( n2 ) )
   {
      n1.output();
      cout << " > ";
      n2.output();
      cout << "\n\n";
   }

   // tests for greater number between n2 and n1 
   if ( n2.greater( n1 ) )
   {
      n2.output();
      cout << " > ";
      n1.output();
      cout << "\n\n";
   }

   // tests for smaller number between n1 and n1
   if ( n1.less( n1 ) )
   {
      n1.output();
      cout << " < ";
      n1.output();
      cout << "\n\n";
   }

   // tests for smaller number between n1 and n2
   if ( n1.less( n2 ) )
   {
      n1.output();
      cout << " < ";
      n2.output();
      cout << "\n\n";
   }

   // tests for smaller number between n2 and n1
   if ( n2.less( n1 ) )
   {
      n2.output();
      cout << " < ";
      n1.output();
      cout << "\n\n";
   }
    
   // tests for smaller or equal number between n1 and n1
   if ( n1.lessEqual( n1 ) )
   {
      n1.output();
      cout << " <= ";
      n1.output();
      cout << "\n\n";
   }

   // tests for smaller or equal number between n1 and n2
   if ( n1.lessEqual( n2 ) )
   {
      n1.output();
      cout << " <= ";
      n2.output();
      cout << "\n\n";
   }

   // tests for smaller or equal number between n2 and n1
   if ( n2.lessEqual( n1 ) )
   {
      n2.output();
      cout << " <= ";
      n1.output();
      cout << "\n\n";
   }
    
   // tests for greater or equal number between n1 and n1
   if ( n1.greaterEqual( n1 ) )
   {
      n1.output();
      cout << " >= ";
      n1.output();
      cout << "\n\n";
   }
    
   // tests for greater or equal number between n1 and n2
   if ( n1.greaterEqual( n2 ) )
   {
      n1.output();
      cout << " >= ";
      n2.output();
      cout << "\n\n";
   }

   // tests for greater or equal number between n2 and n1
   if ( n2.greaterEqual( n1 ) )
   {
      n2.output();
      cout << " >= ";
      n1.output();
      cout << "\n\n";
   }
    
   cout << "----------------------------------------------------------------------" << "\n\n";

   int length3;
   int length4;
   cout << "Enter the lengths of two huge integers: ";
   cin >> length3 >> length4;
   cout << "\n";

	HugeInteger n3( length3 );
   HugeInteger n4( length4 );

   n3.random();
   n4.random();
   
   HugeInteger n5;

   n3.output();
   cout<< " + ";
   n4.output();
   cout << " == ";
   n5 = n3.add( n4 );
   n5.output();// outputs n3 + n4
   cout << "\n\n";
   
   n3.output();
   cout<< " - ";
   n4.output();
   cout << " == ";
   n5 = n3.subtract( n4 );
   n5.output();// outputs n3 - n4
   cout << "\n\n";
   
   n3.output();
   cout<< " * ";
   n4.output();
   cout << " == ";
   n5 = n3.multiply( n4 );
   n5.output();// outputs n3 * n4
   cout << "\n\n";
 
   n3.output();
   cout<< " / ";
   n4.output();
   cout << " == ";
   n5 = n3.divide( n4 );
   n5.output();// outputs n3 / n4
   cout << "\n\n";
   
   n3.output();
   cout<< " % ";
   n4.output();
   cout << " == ";
   n5 = n3.modulus( n4 );
   n5.output();// outputs n3 % n4
   cout << "\n\n";
   
   n3.output();
   cout<< " - (";
   n3.output();
   cout<< " % ";
   n4.output();
   cout << ") == ";
   n3.subtract( n3.modulus( n4 ) ).output(); // outputs n3 - ( n3 % n4 )
   
   cout<< "\n\n(";
   n3.output();
   cout<< " / ";
   n4.output();
   cout<< ") * ";
   n4.output();
   cout << " == ";
   n3.divide( n4 ).multiply( n4 ).output(); // outputs ( n3 / n4 ) * n4
   cout << "\n\n";

   // Note that n3 - ( n3 % n4 ) must be equal to ( n3 / n4 ) * n4

	system("pause");
} // end main