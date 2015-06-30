//
//  main.cpp
//  猜數字
//
//  Created by 吳冠賢 on 2014/10/18.
//  Copyright (c) 2014年 吳冠賢. All rights reserved.
//

#include<iostream>
#include<ctime>

using namespace std;

class Guess{
public :
    Guess();
    
    int judge(int a){
        
        int r;
        
        if(a == answer){
            r = 0;
        }else if(a<answer)
            r = -1;
        else
            r = 1;
        
        return r;
    }

private:
    int answer;
};

Guess::Guess(){
    answer=rand()%100+1;
}

int main(){
    
    srand(time(0));
    
    Guess myAnswer;
    
    int n,a;
    
    cout <<"Guess a number :";
    cin >>n;
    
    while((a = myAnswer.judge(n))){
        
        if(a<0)
            cout <<"Too small.\n";
        else if(a>0)
            cout <<"Too big.\n";
        
        cout <<"answer ? ";
        cin >>n;
    }
    cout << "ya ~ Congratulations ~" <<endl;
}