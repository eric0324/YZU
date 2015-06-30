//
//  main.cpp
//  stack
//
//  Created by 吳冠賢 on 2014/11/6.
//  Copyright (c) 2014年 吳冠賢. All rights reserved.
//

#include <iostream>

using namespace std;

class Stack{
public:
    Stack(int n){
        array = new int[n];
        full = n;
        empty = 0;
        ptr = 0;
    }
    
    int Pop(){
        if (ptr == 0) {
            cout << "Stack is empty!" << endl;
        }
        
        if(ptr == empty)
            return -1;
        ptr--;
        
        return array[ptr];
    }// 取出堆疊中最上層的資料
    
    int Push(int n){
        if (ptr>=full) {
            cout << "Stack is full!" << endl;
        }
        
        if(ptr == full)
            return -1;
        array[ptr] = n;
        ptr++;
        
        return n;
    }// 放入一個資料到堆疊中
    void PrintStack(){
        int i=0;
        for(i=empty;i<ptr;i++)
            cout << array[i] << " ";
        cout << endl;
    }// 用來印出堆疊內的值
    
private:
    int ptr;// 目前指向堆疊的位置
    int *array;
    int full;// 指向堆疊的頂端
    int empty;// 指向堆疊的頂部
};


int main(){
    
    int num;
    cout << "Stack's element number : ";
    cin >> num;
    Stack stk(num);
    
    int cho = -1;
    while(cho != 0){
        cout << "0 : end " << endl;
        cout << "1 : delete a number " << endl;
        cout << "2 : add  a number " << endl;
        cout << "Your chioce:";
        cin>>cho;
        
        if(cho==0)
            break;
        else if(cho==1){
            stk.Pop();
            stk.PrintStack();
            cout<<endl;
        }
        else if(cho==2){
            int add_num;
            cout<<"Input a number : ";
            cin>>add_num;
            stk.Push(add_num);
            stk.PrintStack();
            cout<<endl;
        }
    }
}