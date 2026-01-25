#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)

void selectionSort(int ar[], int n){
	for(int i=0;i<n-1;i++){
		int min = i;
		for(int j=i;j<n;j++){
			if(ar[j]<ar[min]){
				min=j;
			} 
		}
		swap(ar[i], ar[min]);
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
	selectionSort(arr, n);
	for(auto it:arr){
		cout<<it<<" ";
	}

	return 0;
}
