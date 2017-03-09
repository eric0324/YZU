//
//  main.cpp
//  pcII_ch3
//
//  Created by 吳冠賢 on 2014/10/18.
//  Copyright (c) 2014年 吳冠賢. All rights reserved.
//

#include <iostream>

using namespace std;

class Person{
private:
    string name;
    int weight;
    int height;
    
public:
    Person(){
        name = "張三";
        weight=70;
        height=180;
    }
    
    Person(string name){
        this -> name = name;
        weight=70;
        height=180;
    }
    
    Person(string name, int weight, int height){
        this -> name = name;
        this -> height = height;
        this -> weight = weight;
    }
    
    string getName(){
        return name;
    }
    
    double BMI(){
        double h = this -> height/100.0;
        return this -> weight/(h*h);
    }
};


int main(){
    
    Person p1;
    Person p2("李四");
    Person p3("王五",160,100);
    
    cout << "p1 : " << p1.getName() << " " << p1.BMI() << endl;
    cout << "p2 : " << p2.getName() << " " << p2.BMI() << endl;
    cout << "p3 : " << p3.getName() << " " << p3.BMI() << endl;
    
    return 0;
}