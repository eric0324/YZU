// Perform huge integer operations.
#include <iostream>
#include <iomanip>
using namespace std;
#include <ctime>

// Rendomly generates a huge integer
void random( int hugeInteger[], int size );

// Returns true if and only if hugeInt1 == hugeInt2
bool equal( int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size );

// Returns true if and only if hugeInt1 != hugeInt2
bool notEqual( int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size );

// Returns true if and only if hugeInt1 < hugeInt2
bool less( int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size );

// Returns true if and only if hugeInt1 > hugeInt2
bool greater( int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size );

// Returns true if and only if hugeInt1 <= hugeInt2
bool lessEqual( int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size );

// Returns true if and only if hugeInt1 >= hugeInt2
bool greaterEqual( int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size );

// sum = addend + adder
void addition( int addend[], int adder[], int sum[], int addendSize, int adderSize, int &sumSize );

// difference = minuend - subtrahend
void subtraction( int minuend[], int subtrahend[], int difference[],
                  int &minuendSize, int subtrahendSize, int &differenceSize );

// product = multiplicand * multiplier
void multiplication( int multiplicand[], int multiplier[], int product[],
                     int multiplicandSize, int multiplierSize, int &productSize );

// cout << hugeInt1 << op << hugeInt2 << " == " << hugeInt3 << endl << endl;
void printOperation( int hugeInt1[], int hugeInt2[], int hugeInt3[], char op,
                     int hugeInt1Size, int hugeInt2Size, int hugeInt3Size );

// cout << hugeInt1 << string << hugeInt2 << endl << endl;
void print( int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size, char *string );

// function main begins program execution
int main()
{
//   srand( static_cast< int >( time(0) ) );
   unsigned int seed;
   cout << "Enter seed: ";
   cin >> seed;
   cout << endl;
   srand( seed );

   const int arraySize = 80;
   int hugeInt1[ arraySize ] = {0};
   int hugeInt1Size = 30 + rand() % 10;
   random( hugeInt1, hugeInt1Size );

   int hugeInt2[ arraySize ] = {0};
   int hugeInt2Size = ( hugeInt1Size / 2 ) + rand() % ( hugeInt1Size / 2 );
   random( hugeInt2, hugeInt2Size );

   // checks for equality between hugeInt1 and hugeInt2 
   if ( equal( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size ) )
      print( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size, "==" );

   // checks for inequality between hugeInt1 and hugeInt2
   if ( notEqual( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size ) )
      print( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size, "!=" );

   // tests for greater number between hugeInt1 and hugeInt2 
   if ( greater( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size ) )
      print( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size, ">" );

   // tests for greater number between hugeInt2 and hugeInt1 
   if ( greater( hugeInt2, hugeInt1, hugeInt2Size, hugeInt1Size ) )
      print( hugeInt2, hugeInt1, hugeInt2Size, hugeInt1Size, ">" );

   // tests for smaller number between hugeInt1 and hugeInt2
   if ( less( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size ) )
      print( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size, "<" );

   // tests for smaller number between hugeInt2 and hugeInt1
   if ( less( hugeInt2, hugeInt1, hugeInt2Size, hugeInt1Size ) )
      print( hugeInt2, hugeInt1, hugeInt2Size, hugeInt1Size, "<" );
    
   // tests for smaller or equal number between hugeInt1 and hugeInt1
   if ( lessEqual( hugeInt1, hugeInt1, hugeInt1Size, hugeInt1Size ) )
      print( hugeInt1, hugeInt1, hugeInt1Size, hugeInt1Size, "<=" );

   // tests for smaller or equal number between hugeInt1 and hugeInt2
   if ( lessEqual( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size ) )
      print( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size, "<=" );

   // tests for greater or equal number between hugeInt2 and hugeInt2
   if ( greaterEqual( hugeInt2, hugeInt2, hugeInt2Size, hugeInt2Size ) )
      print( hugeInt2, hugeInt2, hugeInt2Size, hugeInt2Size, ">=" );
    
   // tests for greater or equal number between hugeInt1 and hugeInt2
   if ( greaterEqual( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size ) )
      print( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size, ">=" );

   int hugeInt3[ arraySize ] = {0};
   int hugeInt3Size;

   // hugeInt3 = hugeInt1 * hugeInt2;
   multiplication( hugeInt1, hugeInt2, hugeInt3, hugeInt1Size, hugeInt2Size, hugeInt3Size );

   // cout << hugeInt1 << " * " << hugeInt2 << " == " << hugeInt3 << endl << endl;
   printOperation( hugeInt1, hugeInt2, hugeInt3, '*', hugeInt1Size, hugeInt2Size, hugeInt3Size );

   // hugeInt3 = hugeInt1 + hugeInt2
   addition( hugeInt1, hugeInt2, hugeInt3, hugeInt1Size, hugeInt2Size, hugeInt3Size );

   // cout << hugeInt1 << " + " << hugeInt2 << " == " << hugeInt3 << endl << endl;
   printOperation( hugeInt1, hugeInt2, hugeInt3, '+', hugeInt1Size, hugeInt2Size, hugeInt3Size );

   int hugeInt4[ arraySize ] = {0};
   int hugeInt4Size;

   // hugeInt4 = hugeInt3 - hugeInt1
   subtraction( hugeInt3, hugeInt1, hugeInt4, hugeInt3Size, hugeInt1Size, hugeInt4Size );

   // cout << hugeInt3 << " - " << hugeInt2 << " == " << hugeInt4 << endl << endl;
   printOperation( hugeInt3, hugeInt1, hugeInt4, '-', hugeInt3Size, hugeInt1Size, hugeInt4Size );

   // if( hugeInt2 == hugeInt4 ) cout << hugeInt2 << " == " << hugeInt4 << endl << endl;
   if( equal( hugeInt2, hugeInt4, hugeInt2Size, hugeInt4Size ) )
      print( hugeInt2, hugeInt4, hugeInt2Size, hugeInt4Size, "==" );
   else
      cout << "Error!\n\n";

   system( "pause" );
} // end function main

void random( int hugeInteger[], int size )
{
   for( int i = 0; i <= size - 2; i++ )
      hugeInteger[i] = rand() % 10;
   hugeInteger[ size - 1 ] = 1 + rand() % 9;
}

void printOperation( int hugeInt1[], int hugeInt2[], int hugeInt3[], char op,
                     int hugeInt1Size, int hugeInt2Size, int hugeInt3Size )
{
   for( int i = hugeInt1Size - 1; i >= 0; i-- )
      cout << hugeInt1[i];

   cout << " " << op << " ";
   for( int i = hugeInt2Size - 1; i >= 0; i-- )
      cout << hugeInt2[i];

   cout << " == ";
   for( int i = hugeInt3Size - 1; i >= 0; i-- )
      cout << hugeInt3[i];
   cout << endl << endl;
}

void print( int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size, char *string )
{
   for( int i = hugeInt1Size - 1; i >= 0; i-- )
      cout << hugeInt1[i];

   cout << " " << string << " ";

   for( int i = hugeInt2Size - 1; i >= 0; i-- )
      cout << hugeInt2[i];
   cout << endl << endl;
}
bool equal( int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size )
{
	if(hugeInt1Size==hugeInt2Size){ //狦计
		for(int i =hugeInt1Size ; i>=0 ; i--) //皐癸–计暗浪琩
			if(hugeInt1[i]!=hugeInt2[i])
				return false;
	}else{
		return false;
	}
	return true;
}
bool notEqual( int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size )
{
	if(hugeInt1Size==hugeInt2Size){
		for(int i =hugeInt1Size; i>= 0;i--){
			if(hugeInt1[i] != hugeInt2[i])
				return true;
		}
	}else{
		return true;
	}
	return false;

}
bool greater( int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size )
{
	if ( hugeInt1Size >  hugeInt2Size) //计ゑ,﹚ゑ
		return true;
	else if (hugeInt1Size< hugeInt2Size)//计ゑ,﹚ゑ
		return false;
	else{  //计,璶ゑ耕计
		for(int i=hugeInt1Size ; i>=0 ; i--)
			if(hugeInt1[i] < hugeInt2[i])
				return false;
		}
	return true;	
	}
bool less( int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size )
{
	if ( hugeInt1Size < hugeInt2Size)
		return true;
	else if ( hugeInt1 > hugeInt2 )
		return false;
	else{
	for(int i = hugeInt1Size ; i>=0 ; i--){
		if(hugeInt1[i]==hugeInt2[i])
		return false;
		}
	}
	return true;
}
bool lessEqual( int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size )
{
	if ( hugeInt1Size < hugeInt2Size)
		return true;
	else if ( hugeInt1Size > hugeInt2Size )
		return false;
	else{
		for(int i = hugeInt1Size-1 ; i>=0 ; i--){
			if(hugeInt1[i] > hugeInt2[i])
		return false;
		}
	}
		return true;
}
bool greaterEqual( int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size )
{//㎝greater functoin阀├
	if ( hugeInt1Size > hugeInt2Size )
		return true;
	else if ( hugeInt1Size < hugeInt2Size )
		return false;
	else
	{ 
		for( int i = hugeInt1Size-1 ; i >= 0 ; i-- )
		{
			if( hugeInt1[i] < hugeInt2[i] )
				return false;
		}
	}
	return true;
}
void addition( int addend[], int adder[], int sum[], int addendSize, int adderSize, int &sumSize )
{
	sumSize = ( addendSize >= adderSize )? addendSize++:adderSize++;
	for( int i = 0; i <sumSize;i++)//皚﹍て
		sum[i]=0;
	if(addendSize >= adderSize)//狦砆计单计
	{
		for( int i=0 ; i<= adderSize; i++)
			sum[i]=addend[i]+adder[i];
		for( int i = adderSize ; i< addendSize;i++)
			sum[i]=addend[i];
	}
	else//狦砆计计
	{
		for( int i=0 ; i<= addendSize; i++)
			sum[i]=addend[i]+adder[i];
		for( int i = addendSize ; i< adderSize;i++)
			sum[i]=adder[i];
	}
	for( int i=0 ; i< sumSize-1; i++)//矪瞶秈拜肈
		if(sum[i]>9)
		{
			sum[i]-=10;
			sum[i+1]++;
		}
		if (sum[sumSize-1]==0)
			sumSize--;
}
void subtraction( int minuend[], int subtrahend[], int difference[],int &minuendSize, int subtrahendSize, int &differenceSize )
{
	differenceSize = minuendSize;
	for( int i = 0; i <= minuendSize; i++)//﹍て
		difference[i]=0;

	for( int i = 0; i <= subtrahendSize; i++)
		difference[i]=minuend[i]-subtrahend[i];

	for( int i = subtrahendSize+1; i <= minuendSize; i++)//ㄓ矪瞶奔
		difference[i] = minuend[i];

	for (int i =0 ; i < differenceSize; i++)//矪瞶秈拜肈
		if( difference[i]<0)
		{
		difference[i] +=10;
		difference[i+1]--;
		}
		if (difference[differenceSize-1]==0)
			differenceSize--;
}
void multiplication( int multiplicand[], int multiplier[], int product[], int multiplicandSize, int multiplierSize, int &productSize )
{	

	productSize= multiplicandSize + multiplierSize ;

	for( int i =0; i <= productSize; i++)//﹍て
		product[i]=0;

	for(int count=0; count < multiplierSize;count++)
	{	
		
		for (int i=0; i <= multiplicandSize; i++)
		{	
			product[count+i] += multiplicand[i] * multiplier[count];
		}
	}

	for(int i=0; i <=productSize; i++)//矪瞶秈
		if(product[i]>9)
		{
			product[i+1]=product[i+1]+product[i]/10;
			product[i]=product[i]%10;
		}
}