// Compute the square root of a huge integer.
#include <iostream>
#include <iomanip>
using namespace std;
#include <vector>
#include <ctime>

// put a randomly generated positive integer into the array hugeInt
void random( vector< int > &hugeInt );

// compute and return the square root of hugeInt
vector< int > computeSquareRoot( vector< int > hugeInt );

// compute and return the square of hugeInt
vector< int > computeSquare( vector< int > hugeInt );

// if hugeInt1 < hugeInt2, retuen true; otherwise, return false
bool smaller( vector< int > hugeInt1, vector< int > hugeInt2 );

// print hugeInt and squareRoot
void printResult( vector< int > hugeInt, vector< int > squareRoot );

// print the square of squareRoot and the square of ( squareRoot + 1 )
// if hugeInt is less than the square of squareRoot, then print Error
// if hugeInt is not less than the square of ( squareRoot + 1 ), then print Error
void verify( vector< int > hugeInt, vector< int > squareRoot );

// increment hugeInt by 1
void increment( vector< int > &hugeInt );

int main()
{
   unsigned int seed;
   cout << "Enter seed: ";
   cin >> seed;
   cout << endl;
   srand( seed );

   int hugeIntSize = 70 + rand() % 10; // the number of digits of hugeInt
   vector< int > hugeInt( hugeIntSize ); // a huge positive integer in the way that
                                     // hugeInt[0] is the units digit,
                                     // hugeInt[1] is the tens digit,
                                     // hugeInt[2] is the hundreds digit, ...,
                                     // hugeInt[ hugeIntSize - 1 ] is the most significant digit.

   random( hugeInt );

   vector< int > squareRoot = computeSquareRoot( hugeInt );

   printResult( hugeInt, squareRoot );// print hugeInt and squareRoot

   // print the square of squareRoot and the square of ( squareRoot + 1 )
   // if hugeInt is less than the square of squareRoot, then print Error
   // if hugeInt is not less than the square of ( squareRoot + 1 ), then print Error
   verify( hugeInt, squareRoot );

   system( "pause" );
}

// put a randomly generated positive integer into the array hugeInt
void random( vector< int > &hugeInt )
{
   for( unsigned int i = 0; i < hugeInt.size() - 1; i++ )
      hugeInt[i] = rand() % 10;
   hugeInt[ hugeInt.size() - 1 ] = 1 + rand() % 9;
}

// compute and return the square root of hugeInt
vector< int > computeSquareRoot( vector< int > hugeInt )
{
   vector< int > square( hugeInt.size() );
   int sqrtSize = ( hugeInt.size() + 1 ) / 2;
   vector< int > squareRoot( sqrtSize ); 

   /*Delete for(int j =sqrtSize-1 ; j>=0 ;j--){
		for(int i =1;smaller(square,squareRoot);i++){
		squareRoot[j] = i;
		computeSquare(squareRoot);
		}
   }*/

   for (int i = squareRoot.size() - 1; i >= 0; i--) { //Add
	   squareRoot[i] ++;//Add
	   while (smaller(computeSquare(squareRoot), hugeInt)) {//Add
		   squareRoot[i] ++;//Add
	   }//Add
	   squareRoot[i] --;//Add
   }//Add
return squareRoot;
}

// compute and return the square of hugeInt
vector< int > computeSquare( vector< int > hugeInt )
{
   int squareSize = 2 * hugeInt.size();
   vector< int > square( squareSize );

   /*相乘*/
	//Delete for(int count = hugeInt.size()-1 ; count>=0 ; count--){
   for (int count = 0; count < hugeInt.size(); count++){ //Add
	//Delete for(int i = hugeInt.size()-1 ; i >=0  ; i--){
   for (int i = 0; i < hugeInt.size(); i++) // Add
			square[count + i] += hugeInt[count] * hugeInt[i];
	}

	/*處理進位*/
	for(int i=0 ; i<square.size()-1 ; i++) //i--更正為i++
		// Delete if(i != 0){
			if (square[i] > 9){ // i更正為square [ i ]
				square[i+1] = square[i+1] + square[i]/10;
				square[i] = square[i]%10;
			}
		//Delete }else{
		//Delete temp = square[i]/10;
		//Delete square[i] = square[i]%10;
		//Delete square.insert(square.begin(),temp);
		if (square[square.size() - 1] == 0) //Add
			square.pop_back();//Add

   return square;
}

// if hugeInt1 < hugeInt2, return true; otherwise, return false
bool smaller( vector< int > hugeInt1, vector< int > hugeInt2 )
{
   if( hugeInt1.size() < hugeInt2.size() )
      return true;
   if( hugeInt1.size() > hugeInt2.size() )
      return false;

   for( int i = hugeInt1.size() - 1; i >= 0 ; i-- )
   {
      if( hugeInt1[i] < hugeInt2[i] )
         return true;
      if( hugeInt1[i] > hugeInt2[i] )
         return false;
   }

   return false;
}

// print hugeInt and squareRoot
void printResult( vector< int > hugeInt, vector< int > squareRoot )
{
   cout << "The square root of\n\n";
   for( int i = hugeInt.size() - 1; i >= 0; i-- )
      cout << hugeInt[ i ];

   cout << "\n\nis\n\n";
   for( int i = squareRoot.size() - 1; i >= 0; i-- )
      cout << squareRoot[ i ];
   cout << endl << endl;
}

// print the square of squareRoot and the square of ( squareRoot + 1 )
// if hugeInt is less than the square of squareRoot, then print Error
// if hugeInt is not less than the square of ( squareRoot + 1 ), then print Error
void verify( vector< int > hugeInt, vector< int > squareRoot )
{
   for( int i = hugeInt.size() - 1; i >= 0; i-- )
      cout << "-";
   cout << endl << endl;

   vector< int > square = computeSquare( squareRoot );

   cout << "The square of\n\n";

   for( int i = squareRoot.size() - 1; i >= 0; i-- )
      cout << squareRoot[ i ];

   cout << "\n\nis\n\n";

   for( int i = square.size() - 1; i >= 0; i-- )
      cout << square[ i ];
   cout << endl << endl;

   if( smaller( hugeInt, square ) )
      cout << "Error!\n\n";


   vector< int > copy = squareRoot;

   increment( copy );

   square = computeSquare( copy );

   cout << "\nThe square of\n\n";

   for( int i = copy.size() - 1; i >= 0; i-- )
      cout << copy[ i ];

   cout << "\n\nis\n\n";

   for( int i = square.size() - 1; i >= 0; i-- )
      cout << square[ i ];
   cout << endl << endl;

   if( !smaller( hugeInt, square ) )
      cout << "Error!\n\n";
}

// increment hugeInt by 1
void increment( vector< int > &hugeInt )
{
   int term = 0;
   while( hugeInt[ term ] == 9 )
      term++;

   if( term == hugeInt.size() )
      hugeInt.resize( term + 1 );

   for( int i = 0; i < term; i++ )
      hugeInt[ i ] = 0;
   hugeInt[ term ]++;
}