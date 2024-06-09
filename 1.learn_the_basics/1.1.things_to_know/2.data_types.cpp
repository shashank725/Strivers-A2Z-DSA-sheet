#include<bits/stdc++.h>
using namespace std;

int main() {
    // int (4 Bytes) (-2,147,483,648 to 2,147,483,647)
    int x = 10;
    // long
    long long x2 = 150000000;

    // float, double
    float y = 5.6;
    double z = 5;
    cout << "Value of y: " << z << endl;

    // string and getline
    // string a,b;
    // cin >> a >> b;
    // cout << "a  & b: " << a << b; 
    string str;
    getline(cin, str);
    cout << str << endl;

    // char
    char ch = 'h';
    cout << ch;

    return 0;
}