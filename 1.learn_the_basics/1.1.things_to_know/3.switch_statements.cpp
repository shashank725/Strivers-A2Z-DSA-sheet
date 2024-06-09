#include<bits/stdc++.h>
using namespace std;

/*
Take the day no  and print the corresponding day 
for 1 print Monday and so on for 7 print Sunday
*/

int main() {
    int day;
    cin >> day;
    switch(day) {
        case 1:
            cout<<"Monday";
            break;
        case 2:
            cout<<"Teusday";
            break;
        case 3:
            cout<<"Wednesday";
            break;
        case 4:
            cout<<"Thursday";
            break;
        case 5:
            cout<<"Friday";
            break;
        case 6:
            cout<<"Saturday";
            break;
        case 7:
            cout<<"Sunday";
            break;
        default:
            cout<<"Invalid opton!";
            break;
    }
    cout<<endl<<"Program Completed";
    return 0;
}