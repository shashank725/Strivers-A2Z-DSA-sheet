#include <bits/stdc++.h>
using namespace std;

// All operations in stack happens in 'O(1)'

int main() {
    stack<int> st;
    st.push(25);
    st.push(11);
    st.push(2002);
    st.push(7);
    st.emplace(725);

    cout << "Top: " << st.top() << endl;
    st.pop();
    cout << "Top: " << st.top() << endl;

    cout << "Size: " << st.size();
    cout << st.empty();

    stack<int> st2;
    st.swap(st2);

    return 0;    
}