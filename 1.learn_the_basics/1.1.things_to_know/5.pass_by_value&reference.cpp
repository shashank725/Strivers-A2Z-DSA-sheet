#include<bits/stdc++.h>
using namespace std;

// pass by Value
void passByValue(int num) {
    cout<<num<<endl;
    num+=5;
    cout<<num<<endl;
    num+=5;
    cout<<num<<endl;
}

// pass by Reference
void passByReference(int &num) {
    cout<<num<<endl;
    num+=5;
    cout<<num<<endl;
    num+=5;
    cout<<num<<endl;
}

int main() {
    int num=10;
    passByValue(num);
    // passByReference(num);
    cout<<num<<endl;
    return 0;
}