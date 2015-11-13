// Vector test program.
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Vector.h" // include definition of class Vector
using namespace std;

void display( int intArray[] );
int enterChoice();

int main()
{
//   system("mode con:cols=60 lines=22");
   system( "color F0" );
//   srand( static_cast< unsigned int >( time(0) ) );

   unsigned int seed;
   cout << "Enter seed: ";
   cin >> seed;
   cout << endl;
   srand( seed );

   Vector vector1;

   int value = rand() % 100;
   Vector vector2( 10 + rand() % 11, value );
   cout << "vector2.size: " << vector2.getSize() << ", vector2.capacity: " << vector2.getCapacity() << endl;
   vector2.display();

   int intArray[ 20 ];
   for ( int i = 0; i < 20; i++ )
      intArray[ i ] = rand() % 100;
   display( intArray );

   unsigned int first = rand() % 10;
   unsigned int last = 10 + rand() % 11;
   Vector vector3( intArray + first, intArray + last );
   cout << "range: " << first << "-" << last - 1 << endl;
   cout << "vector3.size: " << vector3.getSize() << ", vector3.capacity: " << vector3.getCapacity() << endl;
   vector3.display();

   Vector vector4( vector3.begin() + 2, vector3.end() - 2 );
   cout << "vector4.size: " << vector4.getSize() << ", vector4.capacity: " << vector4.getCapacity() << endl;
   vector4.display();

   Vector vector5( vector3 );
   cout << "vector5.size: " << vector5.getSize() << ", vector5.capacity: " << vector5.getCapacity() << endl;
   vector5.display();

   unsigned int newSize;
   unsigned int newCapacity;
   unsigned int position;
   unsigned int n;
   first = rand() % 11;
   last = 10 + rand() % 11;
   int choice;

   while ( ( choice = enterChoice() ) != 12 ) 
   {
      vector1.assign( intArray + first, intArray + last );
      switch ( choice ) 
      {
         case 1:
            cout << "Before resize: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();

            newSize = 10 + rand() % 11;
            cout << "newSize: " << newSize << endl;
            vector1.resize( newSize );

            cout << "After resize: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();
            break;
         case 2:
            cout << "Before resize: vector1.size = " << vector1.getSize() << endl;
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();

            newSize = 10 + rand() % 11;
            cout << "newSize: " << newSize << endl;
            vector1.resize( newSize, vector1.front() );

            cout << "After resize: vector1.size = " << vector1.getSize() << endl;
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();
            break;
         case 3:
            cout << "Before reserve: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();

            newCapacity = vector1.getCapacity() + 1 + rand() % 10;
            cout << "newCapacity: " << newCapacity << endl;
            vector1.reserve( newCapacity );

            cout << "After reserve: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();

            vector1.shrink_to_fit();

            cout << "After shrink_to_fit: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();
            break;
         case 4:
            cout << "Before assign: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();

            newSize = 10 + rand() % 11;
            value = vector1.back();
            cout << "newSize: " << newSize << ", value: " << value << endl;
            vector1.assign( newSize, value );

            cout << "After assign: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();
            break;
         case 5:
            cout << "Before push_back: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();

            value = vector1.front();
            vector1.push_back( value );

            cout << "After push_back: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();
            break;
         case 6:
            cout << "Before insert: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();

            position = rand() % vector1.getSize();
            value = vector1.back();
            vector1.insert( vector1.begin() + position, value );

            cout << "position: " << position << endl;
            cout << "After insert: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();
            break;
         case 7:
            cout << "Before insert: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();

            position = rand() % vector1.getSize();
            n = 1 + rand() % 10;
            value = vector1.back();
            cout << "position: " << position;
            cout << ", n: " << n;
            cout << ", value: " << value << endl;
            vector1.insert( vector1.begin() + position, n, value );

            cout << "After insert: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();
            break;
         case 8:
            cout << "Before insert: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();

            position = rand() % vector1.getSize();
            first = vector1.getSize() / 4;
            last = vector1.getSize() * 3 / 4;
            cout << "position: " << position;
            cout << ", first = " << first << ", last = " << last << endl;
            vector1.insert( vector1.begin() + position, vector2.begin() + first, vector2.begin() + last );

            cout << "After insert: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();
            break;
         case 9:
            cout << "Before erase: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();

            position = rand() % vector1.getSize();
            cout << "position: " << position << endl;
            vector1.erase( vector1.begin() + position );

            cout << "After erase: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();
            break;
         case 10:
            cout << "Before erase: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();

            first = vector1.getSize() / 4;
            last = vector1.getSize() * 3 / 4;
            cout << "first = " << first << ", last = " << last << endl;
            vector1.erase( vector1.begin() + first, vector1.begin() + last );

            cout << "After erase: vector1.size = " << vector1.getSize();
            cout << ", vector1.capacity = " << vector1.getCapacity() << endl;
            vector1.display();
            break;
         case 11:
            cout << "Before swap: vector4.size = " << vector4.getSize();
            cout << ", vector4.capacity = " << vector4.getCapacity() << endl;
            vector4.display();

            cout << "Before swap: vector5.size = " << vector5.getSize();
            cout << ", vector5.capacity = " << vector5.getCapacity() << endl;
            vector5.display();

            vector5.swap( vector4 );

            cout << "After swap: vector4.size = " << vector4.getSize();
            cout << ", vector4.capacity = " << vector4.getCapacity() << endl;
            vector4.display();

            cout << "After swap: vector5.size = " << vector5.getSize();
            cout << ", vector5.capacity = " << vector5.getCapacity() << endl;
            vector5.display();
            break;
         default: // display error if user does not select valid choice
            cerr << "Incorrect choice" << endl;
            break;
      } // end switch
   } // end while

   system("pause");
} // end main

int enterChoice()
{
   cout << "Enter your choice" << endl
      << "1 - resize( unsigned int n )" << endl
      << "2 - resize( unsigned int n, const int val )" << endl
      << "3 - reserve & shrink_to_fit" << endl
      << "4 - assign( int n, const int val )" << endl
      << "5 - push_back" << endl
      << "6 - insert( int *position, const int val )" << endl
      << "7 - insert( int *position, unsigned int n, const int val )" << endl
      << "8 - insert( int *position, int *first, int *last )" << endl
      << "9 - erase( int *position )" << endl
      << "10 - erase( int *first, int *last )" << endl
      << "11 - swap" << endl
      << "12 - end program\n? ";

   int menuChoice;
   cin >> menuChoice;
   cout << endl;
   return menuChoice;
} // end function enterChoice

void display( int intArray[] )
{
   cout << "intArray: " << endl;
   for ( int i = 0; i < 20; i++ )
   {
      cout << setw(3) << intArray[ i ];
      if( i % 10 == 9 || i == 49 )
         cout << endl;
   }
   cout << endl;
}