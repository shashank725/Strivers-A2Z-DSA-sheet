#include <bits/stdc++.h>
using namespace std;

void Nto1(int n){
	if(n==0) return;
	cout<<n<<" ";
	Nto1(n-1);
}

int main() {
    int t;
	cin>>t;
	while(t--) {
        int n;
        cin>>n;
	    Nto1(n);
	}
	cout<<endl;

}