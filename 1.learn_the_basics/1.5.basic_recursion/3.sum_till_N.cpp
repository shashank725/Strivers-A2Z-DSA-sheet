#include <bits/stdc++.h>
using namespace std;

// Parameterised Recursion
void sumTillN(int i, int sum){
	// if(i<1){
	// 	cout<<sum;
	// 	return;
	// }
	// sumTillN(i-1, sum+i);
}

// Functional Recursion
int sumTillN_2(int n) {
	if(n==0){
		return 0;
	}
	return n + sumTillN_2(n-1);
}


int main() {
    int t;
	cin>>t;
	while(t--) {
        int n;
        cin>>n;
	    // sumTillN(n,0);
	cout<<sumTillN_2(n);
	}
	cout<<endl;

}