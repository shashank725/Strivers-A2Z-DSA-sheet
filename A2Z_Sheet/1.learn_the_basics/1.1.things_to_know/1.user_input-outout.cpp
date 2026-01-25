#include<iostream>
using namespace std;


int main() {
    // When not using namespace
    // std::cout << "Hey!" << "\n";
    // std::cout<<"Shashank"<<std::endl;

    cout << "Hey" << "\n" << "Shashank" << endl;

    int x, y;
    cin >> x >> y;
    cout<<"Value of 'x':"<<x<<" and 'y':"<<y;

    return 0;
}