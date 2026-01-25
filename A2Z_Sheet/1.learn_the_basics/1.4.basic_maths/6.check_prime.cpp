#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int x) {
    int cnt = 0;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            cnt+=1;
            if(x/i!=i) cnt+=1;
        }
    }
    if(cnt==2) return true;
    return false;
}

int main() {
    int t;
	cin>>t;
	while(t--) {
        int n;
        cin>>n;
	    cout<<checkPrime(n);
	}
	cout<<endl;

}
