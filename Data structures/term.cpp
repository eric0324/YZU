#include <iostream>
using namespace std;

struct Term {
    int expon, coef;
} a[3000], b[3000], c[3000];


void showPoly(Term *x, int terms) {
    for (int i = 0; i < terms; i++) {
        if (x[i].coef > 0 && i > 0)
            cout << "+" << x[i].coef;
        else
            cout << x[i].coef;
        cout << "x^" << x[i].expon << " ";
    }
    cout << endl;
}

int main() {
    int a_term, b_term, i, j, k, c_term;
    
    cout << "Input A(x):" << endl;
    cout << "項數 = ";
    cin >> a_term;
    for (i = 0; i<a_term; i++){
        cout << "第 " << i + 1 << " 項:" << endl;
        cout << "係數 = ";
        cin >> a[i].coef;
        cout << "指數 = ";
        cin >> a[i].expon;
    }
    cout << "Input B(x):" << endl;
    cout << "項數 = ";
    cin >> b_term;
    for (i = 0; i<b_term; i++){
        cout << "第 " << i + 1 << " 項:" << endl;
        cout << "係數 = ";
        cin >> b[i].coef;
        cout << "指數 = ";
        cin >> b[i].expon;
    }
    c_term = 0;
    
    for (i = 0; i < a_term; i++) {
        for (j = 0; j < b_term; j++) {
            //a , b兩個多項式乘開存到c
            int tmpExp = a[i].expon + b[j].expon;
            int tmpCoef = a[i].coef * b[j].coef;
            bool isSameExp = false;
            for (k = 0; k < c_term; k++) {
                if (tmpExp == c[k].expon) {
                    c[k].coef += tmpCoef;
                    isSameExp = true;
                    break;
                }
            }
            
            if (!isSameExp) {
                c[k].coef = tmpCoef;
                c[k].expon = tmpExp;
                c_term++;
            }
            //根據expon 讓多項式排序
            while (k > 0) {
                if (c[k].expon > c[k - 1].expon)
                    swap(c[k], c[k - 1]);
                k--;
            }
        }
    }
    
    cout << "A(x) = ";
    showPoly(a, a_term);
    
    cout << "B(x) = ";
    showPoly(b, b_term);
    
    cout << "Result = ";
    showPoly(c, c_term);
    
    system("pause");
}