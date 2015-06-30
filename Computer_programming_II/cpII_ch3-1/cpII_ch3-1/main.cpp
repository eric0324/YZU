//
//  main.cpp
//  cpII_ch3-1
//
//  Created by 吳冠賢 on 2014/10/23.
//  Copyright (c) 2014年 吳冠賢. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    
    int a,b,ansI;
    double ansD;
    
    while (cin >> a >> b && (a||b) ) {
        int cnt =0 ;
        for (int i = a; i<=b; i++) {
            ansI = sqrt(i);
            ansD = sqrt(i);
            
            if (ansD == ansI) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    
}