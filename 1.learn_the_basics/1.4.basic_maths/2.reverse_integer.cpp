#include <bits/stdc++.h>
using namespace std;

int reverse(int x) {
        int ans = 0;
        while(x!=0){
            int digit = x%10;
            if(ans>INT_MAX/10 || ans<INT_MIN/10)
                return 0;
            ans = (ans*10)+digit;
            x = x/10;
        }
        return ans;
    }

int main() {
    int t;
	cin>>t;
	while(t--) {
        int n;
        cin>>n;
	    cout<<reverse(n);
	}
	cout<<endl;

}
