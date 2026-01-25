#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) ->average & worst
// TC: O(n) ->best

void bubble_sort(int arr[], int n) {
    // Base Case: range == 1.
    if (n == 1) return;

    int didSwap = 0;
    for (int j = 0; j <= n - 2; j++) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            didSwap = 1;
        }
    }

    // if no swapping happens.
    if (didSwap == 0) return;

    //Range reduced after recursion:
    bubble_sort(arr, n - 1);
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
	bubble_sort(arr, n);
	for(auto it:arr){
		cout<<it<<" ";
	}

	return 0;
}