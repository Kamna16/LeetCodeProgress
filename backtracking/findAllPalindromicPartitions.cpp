#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<string>> ans;
    int n;
    bool isPalindrome(int i,int j,string s)
    {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int ind, string &s, vector<string> &curr)
    {
        if(ind == n){
            ans.push_back(curr);
            return;
        }
        
        for(int i=ind;i<n;i++)
        {
            if(isPalindrome(ind,i,s)){
                curr.push_back(s.substr(ind, i - ind + 1));
                solve(i + 1, s, curr);
                curr.pop_back(); 
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        n = S.size();
        vector<string> temp;
        solve(0,S,temp);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}