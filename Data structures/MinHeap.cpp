//1013353 吳冠賢 2015/05/30 hw_5

//Write a program to implement the following jobs for a Min Heap which is represented with an array.

#include <iostream>
#define MAX 500

using namespace std;

#define PARAENT(i)  (i/2)
#define LEFT(i)     (2*i+1)
#define RIGHT(i)    (2*i+2)

int lenght;
void swap(int* lhs, int* rhs)
{
    int tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}

void minHeapify(int* a, int heapSize, int i)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int smallest;
    if(l < heapSize && a[l] < a[i])
        smallest = l;
    else
        smallest = i;
    if(r < heapSize && a[r] < a[smallest])
        smallest = r;

    if(smallest != i)
    {
        swap(a + i, a + smallest);
        minHeapify(a, heapSize, smallest);
    }
}

// creat min heap
void buildMinHeap(int* a, int n)
{
    for(int i = n/2; i >= 0; --i)
        minHeapify(a, lenght, i);
}

// sort
void heapSort(int* a, int n)
{
    buildMinHeap(a, n);

    //題目不確定是否要排序？
    /*
    for(int i = n - 1; i >= 1; --i)
    {
        swap(a, a + i);
        n -= 1;
        minHeapify(a, n, 0);
    }*/
}

int main()
{

    int a[MAX];
    int del;
    cin >> lenght;
    cout << "I ";
    for(int i = 0;i<lenght;i++)
      cin >> a[i];

    heapSort(a, lenght);

    for(int i = 0; i < lenght; ++i)
        cout << a[i] << ' ';

    cout << endl;

    //是delete 題目的元素還是heap好的元素？
    while(cin >> del){
          a[del-1]=0x00;
          heapSort(a, lenght);
          for(int i = 0; i < lenght; ++i)
            if(a[i]!=0)
              cout << a[i] << ' ';
          cout << endl
      }
    heapSort(a, lenght);
}
