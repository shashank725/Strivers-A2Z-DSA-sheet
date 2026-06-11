#include<iostream>
#include<vector>
using namespace std;


// Using string reference to avoid unnecessary copying of strings in recursive calls
class Solution{
public:
    void func(int idx, string& s, vector<string>& path, vector<vector<string>>& ans){
        int n = s.size();
        if(idx == n){
            ans.push_back(path);
            return;
        }
        for(int i=idx; i<n;i++) {
            if(isPalindrome(idx, i, s)){
                path.push_back(s.substr(idx, (i-idx)+1));
                func(i+1, s, path, ans);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(int start, int end, string& s){
        while (start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        func(0, s, path, ans);
        return ans;
    }
};