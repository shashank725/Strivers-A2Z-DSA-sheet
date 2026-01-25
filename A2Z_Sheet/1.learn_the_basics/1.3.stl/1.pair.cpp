#include<bits/stdc++.h>
using namespace std;

int main() {
    pair<int, int> p = {1,2};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> p2 = {1, {2, 3}};
    cout<<p2.first<<" "<<p2.second.first<<" "<<p2.second.second<<endl;

    pair<int, int> arr[] = {{25, 11}, {11, 2002}, {25, 2002}};
    cout << arr[1].second;
}