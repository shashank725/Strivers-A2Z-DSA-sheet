#include <bits/stdc++.h>
using namespace std;

// TC: O(N log(base 2) N)
// SC: O(N)

void merge(int arr[], int temp[], int low, int mid, int high){
	// vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr
	
	int index = low;

    //storing elements in the temporary array in a sorted manner//
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            // temp.push_back(arr[left]);
            // left++;
			temp[index++] = arr[left++];
        }
        else {
            // temp.push_back(arr[right]);
            // right++;
			temp[index++] = arr[right++];

        }
	}
    // if elements on the left half are still left //
    while (left <= mid) {
        // temp.push_back(arr[left]);
        // left++;
		temp[index++] = arr[left++];

    }
    //  if elements on the right half are still left //
    while (right <= high) {
        // temp.push_back(arr[right]);
        // right++;
		temp[index++] = arr[right++];

    }
    // transfering all elements from temporary to arr //
    // for (int i = low; i <= high; i++) {
    //     arr[i] = temp[i - low];
    // }
	for(int i=low;i<=high;i++){
		arr[i] = temp[i];
	}
}

void ms(int ar[], int temp[], int low, int high){
	if (low == high) return;
    int mid = (low + high) / 2 ;
    ms(ar, temp, low, mid);  // left half
    ms(ar, temp, mid + 1, high); // right half
    merge(ar, temp, low, mid, high);  // merging sorted halves
}

void mergeSort(int arr[], int n){
	int *temp = new int[n];
	ms(arr, temp, 0, n-1);
	delete[] temp;
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
	mergeSort(arr, n);
	for(auto it:arr){
		cout<<it<<" ";
	}

	return 0;
}



// int main() {
// 	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     int t;
// 	cin>> t;
// 	while(t--) {
//         int n;
// 		cin>>n;
// 	}
// }