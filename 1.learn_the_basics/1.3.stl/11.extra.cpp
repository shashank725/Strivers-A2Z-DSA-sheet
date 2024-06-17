#include <bits/stdc++.h>
using namespace std;

// comparator
bool comp(pair<int, int> p1, pair<int, int>p2) {
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    // when second ele is same
    if(p1.first > p1.first) return true;
    return false;
}

int main() {
    int arr[] = {1, 5 , 3, 2};
    for(auto i:arr) {
        cout<<i<<" ";
    }
    cout<<endl<<"Size of arr: "<<sizeof(arr)/sizeof(arr[0])<<endl;

    //  Sorting in asc order
    cout<<"After sorting=";
    sort(arr, arr+4);
    // sort(vector.begin(), vector.end());
    for(auto i:arr) {
        cout<<i<<" ";
    }
    //  Sorting in desc order
    cout<<endl<<"Soring in desc order=";
    sort(arr, arr+4, greater<int>());
    for(auto i:arr) {
        cout<<i<<" ";
    }
    cout<<endl;


// "Sort in your condition"
    //  Sort is acording to second element
    //  if second element is same, then sort
    //  it according to first element but in desc order
    pair<int, int> ar[] = {{1, 10}, {2, 20}, {3, 30}};
    sort(ar, ar+3, comp);



    int num = 7;       // '111' in binary
    int cnt = __builtin_popcount(num);
    long long num2 = 25112000007;
    int cnt2 = __builtin_popcountll(num2);
    cout<<"num="<<cnt<<endl<<"long long="<<cnt2<<endl;

// Permutation of a string
    string s = "132";
    sort(s.begin(), s.end());    //good pratice to sort
    do {
        cout<<s<<endl;
    } while(next_permutation(s.begin(), s.end()));
    
// Max element in an array
    int maxi = *max_element(arr, arr+4);
    cout<<"Max element of arr: "<<maxi;

    return 0;    
}