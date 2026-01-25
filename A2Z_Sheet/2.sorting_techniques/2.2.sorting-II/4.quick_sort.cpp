#include <bits/stdc++.h>
using namespace std;

// TC: O(N log(base 2) N)
// SC: O(1)

int partition(int arr[], int low, int high){
	int pivot = arr[low];
	int left = low;
	int right = high;
	while(left<right){
		while(arr[left]<=pivot && left<=high-1){
			left++;
		}
		while(arr[right]>pivot && right>=low+1){
			right--;
		}
        
		if(left<right) swap(arr[left], arr[right]);
	}
	swap(arr[low], arr[right]);
	return right;
}

void quickSort(int arr[], int low, int high) {
        if(low<high){
		 	int partitionIndex = partition(arr, low, high);
		 	quickSort(arr, low, partitionIndex-1);
		 	quickSort(arr, partitionIndex+1, high);
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
	quickSort(arr, 0, n-1);
	for(auto it:arr){
		cout<<it<<" ";
	}

	return 0;
}