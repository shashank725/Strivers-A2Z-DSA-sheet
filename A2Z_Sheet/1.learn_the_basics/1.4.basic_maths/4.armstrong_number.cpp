#include <bits/stdc++.h>
using namespace std;

int countDigit(int n) {
    int count = (int) (log10(n) + 1);
    return count;
}
int armstrong(int n) {
    int sum = 0;
    int temp = n;
    int order = countDigit(n);
    while(temp) {
        int digit = temp%10;
        sum = sum + pow(digit, order);
        temp = temp/10;
    }
    if(sum==n) return true;
    return false;
}

int main() {
    int t;
	cin>>t;
	while(t--) {
        int n;
        cin>>n;
	    cout<<armstrong(n);
	}
	cout<<endl;

}
