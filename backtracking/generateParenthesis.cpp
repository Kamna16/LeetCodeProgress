#include<bits/stdc++.h>
using namespace std;

// check is valid parenthesis : open = +1, clost = -1
// if overall sum is 0 --> valid

// 1) use backtracking and then check if your current ans is valid parenthesis
class Solution {
public:
    vector<string> ans;
    bool isValid(string s)
    {
        int count =0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(') count++;
            else count--;
            if(count < 0) return false;
        }
        return count==0;
    }
    void solve(string &curr, int n)
    {
        if(curr.length() == 2*n)
        {
            if(isValid(curr))
            {
                ans.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();

        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();
        
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr,n);
        return ans;
    }
};

// 2) removing unnecessary strings

class Solution {
public:
    vector<string> ans;
    void solve(string &curr, int n,int open, int close)
    {
        if(curr.length() == 2*n)
        {
            ans.push_back(curr);
            return;
        }
        if(open<n)
        {
            curr.push_back('(');
            solve(curr,n,open+1,close);
            curr.pop_back();
        }
        if(close < open){
            curr.push_back(')');
            solve(curr,n,open,close+1);
            curr.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr,n,0,0);
        return ans;
    }
};