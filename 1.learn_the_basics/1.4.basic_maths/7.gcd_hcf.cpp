#include <bits/stdc++.h>
using namespace std;

// Imp: a*b = lcm(a,b) * gcd(a,b)  

int gcd(int a, int b){
	while (a>0 && b)	
	{
		if(a>b) a=a%b;
		else b=b%a;
	}
	if(a==0) return b;
	return a;
	
}


int main() {
    int t;
	cin>>t;
	while(t--) {
        int n, m;
        cin>>n>>m;
	    cout<<gcd(n, m);
	}
	cout<<endl;

}