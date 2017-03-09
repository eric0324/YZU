//
//  main.cpp
//  Crypher
//
//  Created by 吳冠賢 on 2014/10/19.
//  Copyright (c) 2014年 吳冠賢. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

class Crypher{
    
private:
    string str, newStr;
    int n,choice;
    
public:
    Crypher(){
        n = 3;
        str = " ";
        
    } // 預設位移 3 位
    
    void input(){
        cout << "Input a key : " ;
        cin >> n;
        cout << "Chioce a model(1:Encoding, 2:Decoding) : ";
        cin >> choice;
        
        if (choice == 1)
            Encoding(n);
        else if(choice == 2)
            Decoding(n);
        
        
        
    }
    
    string Encoding(int n){

        cin.ignore() ;
        cout << "Enter a text : ";
        getline(cin, str);
        
        for(int i=0;str[i]!='\0';i++)
            if(str[i] == ' ')
                newStr[i]=' ';
            else
                newStr[i]=(str[i]+n-'a'+26) %26 +'a';

        return str;
        
    }// 輸入一個字串並且加密
    
    string Decoding(int n){
        
        cin.ignore() ;
        cout << "Enter a text : ";
        getline(cin, str);
        //tolower(str);
        for(int q=0;str[q]!='\0';q++)
            if(str[q] == ' ')
                newStr[q]=' ';
            else
                newStr[q]=(str[q]-n-'a'+26) %26 +'a';
        
        return str;
    }//輸入一個字串並且解密
    
    void output(){
        cout << endl;
        cout << "******************************************" << endl;
        for (int m=0; newStr[m]!='\0'; m++) {
            cout << newStr[m];
        }
        cout << endl;
    }
};


int main() {
    Crypher pw;
    
    pw.input();
    pw.output();
}
