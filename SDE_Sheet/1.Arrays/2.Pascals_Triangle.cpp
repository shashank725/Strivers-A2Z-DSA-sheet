#include <iostream>
using namespace std;

// Variation 1 : In this case, we are given the row number r and the
// column number c, and we need to find out the element at position (r,c).
// Brute Force Approach
// TC: O(c)
// SC: O(1)
int nCr(int n, int r) {
    long long res = 1;
    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}


// Variation 2 : Given the row number n. Print the n-th row of Pascal’s triangle.
// TC: O(N)
// SC: O(1)
void pascalTriangle2(int n) {
    long long ans = 1;
    cout << ans << " "; // printing 1st element
    //Printing the rest of the part:
    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}


// Variation 3 : 
// TC: O(n*n*r) - O(n3)
// SC: O(1)
vector<vector<int>> pascalTriangle3(int n) {
    vector<vector<int>> ans;

    //Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}
// Optimal Approach
// TC: O(N2)
// SC: O(1)
vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> pascalTriangle3_2(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}


int main() {
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: "
            << element << "\n";
    pascalTriangle2(5);

    vector<vector<int>> ans = pascalTriangle3(5);
    cout<<"The Pascal's Triangle is: \n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    vector<vector<int>> ans2 = pascalTriangle3_2(5);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}