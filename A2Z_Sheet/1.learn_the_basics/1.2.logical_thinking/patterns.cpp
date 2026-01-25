#include<bits/stdc++.h>
using namespace std;

void pattern1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern2(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++) {
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern3(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++) {
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}

void pattern4(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++) {
            cout<<i;
        }
        cout<<endl;
    }
}

void pattern5(int n){
    for(int i=n;i>0;i--){
        for(int j=i;j>0;j--) {
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern6(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++) {
            cout<<j;
        }
        cout<<endl;
    }
}

void pattern7(int n){
    for(int i=0;i<n;i++) {
        // space
        for(int j=0;j<n-i-1;j++) {
            cout<<" ";
        }
        // star
        for(int j=0;j<(i*2)+1;j++) {
            cout<<"*";
        }
        // space
        for(int j=0;j<n-i-1;j++) {
            cout<<" ";
        }
        cout<<endl;
    }
}



int main() {
    int t;
    cin>>t;
    while(t>0) {
        int input;
        cin>>input;
        // pattern1(input);
        // pattern2(input);
        // pattern3(input);
        // pattern4(input);
        // pattern5(input);
        // pattern6(input);
        pattern7(input);
        t--;
    }
    return 0;
}