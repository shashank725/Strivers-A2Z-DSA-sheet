#include <bits/stdc++.h>
using namespace std;

// Stores multiple same elements in a sorted order

int main() {
    multiset<int> ms;
    ms.insert(25);
    ms.insert(25);
    ms.insert(25);
    ms.insert(25);
    for(auto i:ms) cout<<i<<" ";
    cout<<endl;

    ms.erase(25);
    cout << "Updated= ";
    for(auto i:ms) cout<<i<<" ";
    cout<<endl;

    multiset<int> ms2;
    ms2.insert(7);
    ms2.insert(7);
    ms2.insert(7);
    ms2.insert(7);
    ms2.insert(7);
    cout << "Ms2: ";
    for(auto i:ms2) cout<<i<<" ";
    cout<<endl;
    cout << "Count of 7: " << ms2.count(7) << endl;

    ms2.erase(ms2.find(7));
    ms2.erase(ms2.find(7), ms2.find(7));
    for(auto i:ms2) cout<<i<<" ";

    return 0;    
}

void explainUSet() {
    unordered_set<int>un_set;
    // Same function as above
}