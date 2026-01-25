#include <bits/stdc++.h>
using namespace std;

// All operations in queue happens in 'O(1)'

int main() {
    queue<int> q;
    q.push(25);
    q.emplace(11);
    q.emplace(2000);

    q.back() += 2;
    cout << "Back: " << q.back() << endl;
    cout << "Front: " << q.front() << endl;

    q.pop();
    cout << "First: " << q.front() << endl;

    return 0;    
}