#include <bits/stdc++.h>
using namespace std;

void printDivisors(int x) {
    // Brute force
    // for(int i=1;i<=x;i++) {
    //     if(x%i==0) cout<<i<<" ";
    // }

    // Optimal Sol
    vector<int> v;
    for(int i=1;i<=sqrt(x);i++) { // 'i*i<=n' can be used instead of sqrt(x)
        if(x%i == 0) 
            v.push_back(i);
            if(x/i != i) v.push_back(x/i);
    }
    sort(v.begin(), v.end());
    for(auto it:v)
        cout<<it<<" ";
}

int main() {
    int t;
	cin>>t;
	while(t--) {
        int n;
        cin>>n;
	    printDivisors(n);
	}
	cout<<endl;

}
