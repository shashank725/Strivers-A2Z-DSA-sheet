#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) ->average & worst
// TC: O(n) ->best

void bubbleSort(int ar[], int n){
	for(int i=n-1;i>0;i--) {
        bool didSwap = false;
		for(int j=0;j<i;j++){
			if(ar[j]>ar[j+1]){
				int temp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = temp;
                didSwap = true;
			}
		}
        if(didSwap==false) break;
	}
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(auto it:arr){
		cout<<it<<" ";
	}
	cout<<endl;
	bubbleSort(arr, n);
	for(auto it:arr){
		cout<<it<<" ";
	}

	return 0;
}

