#include <bits/stdc++.h>
using namespace std;

// Stores unique elements in a sorted order

int main() {
    set<int> s; 
    s.insert(25);
    s.insert(11);
    s.emplace(2002);
    for(auto it:s) cout << it << " ";

    auto it = s.find(25);
    // 'it' will point to the address of '25'

    auto it2 = s.find(7);
    // 7 is not there so, 'it' will point to 's.end()'

    int cnt = s.count(7);
    cout << endl << cnt<< endl;

    s.erase(2002);
    s.erase(it);  
    auto a = s.find(25);
    auto b = s.find(11);
    s.erase(b, a);

    // s.insert(25);
    // s.insert(11);
    // s.emplace(2002);
    auto c = s.lower_bound(2);
    auto d = s.upper_bound(25);
    


    return 0;    
}