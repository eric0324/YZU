#include <iostream>
#include <iomanip>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <cmath>

#define MAX 1234

using namespace std;

int itration;
long double ansArr[MAX];
int curIndex=0;

void *calPi(void *g){
    long double ans;
    int maxInteger = numeric_limits<int>::max();
    srand((unsigned)time(NULL));
    int index = 0, calcSum=0, hit=0;
    long double length, angle, posit, top, bottom, sumLength=0;

    while(index < itration){

        length=rand()/(long double)maxInteger;
        angle=rand()/(long double)100;
        posit=rand()/(long double)100;

        top = posit + abs(length * sin(angle));
        bottom = posit;


        if(ceil(bottom)==floor(top)){
            ++hit;
        }

        sumLength += length;
        ++calcSum;

        index++;
    }
    ans= ((long double)2*sumLength)/(long double)hit;
    ansArr[curIndex++]=ans;
}

int main() {
    int threadNum;
    pthread_t threads[MAX];
    int angle=1;
    int *length=&angle;
    int morethread, i;

    cin >> itration >> threadNum;

    //Calculate time Start
    time_t nStart = time(NULL);

    for (i = 0; i < threadNum; i++)
        morethread=pthread_create(&threads[i],NULL,calPi,length);

    for (i = 0; i < threadNum; i++)
        morethread=pthread_join(threads[i],NULL);

    long double ans=0;

    for (i = 0; i < threadNum; i++)
        ans+=ansArr[i];

    //Calculate time End...
    time_t nEnd = time(NULL);
    int calTime = nEnd-nStart ;

    //Output
    cout << setprecision(100) << ans/(long double)threadNum << endl;
    cout << "(" << itration << " iteration, " << calTime << "ms, calculate with " << threadNum << " threads)" << endl;

}
