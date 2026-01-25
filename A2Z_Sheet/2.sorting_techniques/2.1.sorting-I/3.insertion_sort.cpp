#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) ->average & worst
// TC: O(n) ->best

void insertionSort(int ar[], int n){
	for(int i=0;i<n;i++){
		int j=i;
		while(j>0 && ar[j-1]>ar[j]){
			int temp = ar[j-1];
			ar[j-1] = ar[j];
			ar[j] = temp;
			j--;
		}
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
	insertionSort(arr, n);
	for(auto it:arr){
		cout<<it<<" ";
	}

	return 0;
}