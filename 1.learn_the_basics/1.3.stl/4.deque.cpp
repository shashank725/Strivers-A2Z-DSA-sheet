#include <bits/stdc++.h>
using namespace std;


int main() {
    deque<int> dq;
    dq.push_back(11);
    dq.emplace_back(2002);

    dq.push_front(25);
    dq.emplace_front(007);

    dq.pop_front();

    for(auto it:dq) cout<<it<<" ";

    // rest functions are same as vector

    return 0;
}
