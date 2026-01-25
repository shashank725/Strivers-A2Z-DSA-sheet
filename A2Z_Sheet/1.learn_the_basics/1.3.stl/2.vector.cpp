#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> v;
    v.push_back(25);
    v.emplace_back(11);     //Faster then 'push_back'
    v.emplace_back(2002);

    vector<pair<int, int>> vec;
    vec.push_back({25, 11});
    vec.emplace_back(25, 11);

    vector<int> v1(5);
    vector<int> v12(5, 100);
    vector<int> v2(v1);

    vector<int>::iterator it = v.begin();
    it++;
    cout << *(it) << " ";
    it = it + 1;
    cout << *(it) << endl;

    vector<int>::iterator it1 = v.end();
    // vector<int>::iterator it2 = v.rend();
    // vector<int>::iterator it3 = v.rbegin();

    cout<<"v[0]: "<<v[0]<<" "<<v.at(0)<<endl;
    cout<<v.back()<<endl;


    for(vector<int>::iterator it = v.begin(); it!=v.end(); it++) {
        cout<<*(it)<< " ";
    }
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }
    cout<<endl;

    for(auto it:v) {
        cout << it << endl;
    }


    v12.erase(v.begin()+1);
    v1.erase(v.begin()+1, v.begin()+3);

    vector<int> v3(2, 100);
    v3.insert(v3.begin(),300);
    v3.insert(v3.begin()+1, 2, 25);

    vector<int> v4(2,50);
    v3.insert(v3.begin(), v4.begin(), v4.end());

    cout<<"Size of v: "<<v.size()<<endl;

    v.pop_back();
    v3.swap(v4);

    v3.clear();
    cout<<v.empty();


    return 0;
}
