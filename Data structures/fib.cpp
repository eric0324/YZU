//
//  main.cpp
//  ds_hw1
//
//  Created by 吳冠賢 on 3/20/15.
//  Copyright (c) 2015 吳冠賢. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include<cmath>

using namespace std;

long long int fibRec (long long int n) {
    if (n <= 0){
        return 0;
    }else if (n == 1){
        return 1;
    }else{
        return fibRec(n-1) + fibRec(n-2);
    }
}

long long int fibIter (long long int n){
    long long int i, twoback, oneback, current;
    if (n <= 0) {
        return 0;
    }else if (n == 1){
        return 1;
    }else{
        twoback = 0;
        oneback = 1;
        for(i=2; i<=n; i++){
            current = twoback + oneback; twoback = oneback;
            oneback = current;
        }
        return current;
    }
}



int main() {
    cout << "Recursive Fibonacci Number" << endl << endl;
    cout << setw(5) << "n" << setw(20) << "f(n)" << setw(20) << "repetitions" << setw(20) << "time" << endl;
    cout << "--------------------------------------------------------------------"<< endl;
    
    for (int i=0; i<=40; i+=5) {
        
        cout << setw(5) << i ;
        double start = clock();
        cout <<setw(20) << fibRec(i);
        double end = clock();
        clock_t clockTicksTaken = end - start;
        double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
        cout << setw(20) <<  ceil( 1/timeInSeconds);
        cout << setw(20) << timeInSeconds << endl;
    }
    
    for (int i=41; i<=50; i++) {
        cout << setw(5) << i ;
        double start = clock();
        cout <<setw(20) << fibRec(i);
        double end = clock();
        clock_t clockTicksTaken = end - start;
        double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
        cout << setw(20) << ceil( 1/timeInSeconds);
        cout << setw(20) << timeInSeconds << endl;
    }
    
    
    cout << endl << endl;
    cout << "Iterative Fibonacci Number" << endl << endl;
    cout << setw(5) << "n" << setw(20) << "f(n)" << setw(20) << "repetitions" << setw(20) << "time" << endl;
    cout << "--------------------------------------------------------------------"<< endl;
    
    for (int i=0; i<=40; i+=5) {
        
        cout << setw(5) << i ;
        double start = clock();
        cout <<setw(20) << fibIter(i);
        double end = clock();
        clock_t clockTicksTaken = end - start;
        double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
        cout << setw(20) <<  ceil( 1/timeInSeconds);
        cout << setw(20) << timeInSeconds << endl;
    }
    
    for (int i=41; i<=50; i++) {
        cout << setw(5) << i ;
        double start = clock();
        cout <<setw(20) << fibIter(i);
        double end = clock();
        clock_t clockTicksTaken = end - start;
        double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
        cout << setw(20) << ceil( 1/timeInSeconds);
        cout << setw(20) << timeInSeconds << endl;
    }

}