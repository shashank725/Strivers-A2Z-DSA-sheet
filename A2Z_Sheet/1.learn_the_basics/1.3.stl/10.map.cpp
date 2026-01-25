#include <bits/stdc++.h>
using namespace std;

// Map stores unique keys in sorted order

int main() {
    map<int, int> mpp;
    map<int, pair<int, int>> mpp1;
    mpp[1] = 10;
    mpp.insert({2, 20});
    mpp.emplace(3, 30);
    mpp[4] = 40;
    

    mpp1[2] = {25, 11};
    // mpp1.emplace(3, 4, 5);

    for(auto it:mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<mpp[25]<<endl;

    auto find = mpp.find(3);
    cout<<"Find 3= "<<find->second<<endl;
    // cout<<"Find 3= "<<(*find).second<<endl;

    auto a = mpp.lower_bound(2);
    auto b = mpp.upper_bound(2);
    cout<<"mpp.lower_bound(2)="<<(*a).second<<endl;
    cout<<"mpp.upper_bound(2)="<<(*b).second<<'\n';

    // erase, swap, size, empty are same
    return 0;    
}
// Map: O(logn)
// unordered map: O(1); worst:O(n)

// Multimap stores duplicate keys in sorted order
// Unordered Map stores unique keys in random order
