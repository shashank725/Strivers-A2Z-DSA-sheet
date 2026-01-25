#include <bits/stdc++.h>
using namespace std;

void reverseArray(int i, int arr[], int n) {
	if(i>=n/2) return;
	swap(arr[i], arr[n-1-i]);
	reverseArray(i+1, arr, n);
}

int main() {
    int t;
	cin>>t;
	while(t--) {
        int n;
		cin>>n;
		int array[n];
		for(int i=0;i<n;i++)
			cin>>array[i];
		reverseArray(0, array, n);
		for(int i=0;i<n;i++){
			cout<<array[i]<<" ";
		}
	}
	cout<<endl;

}