class Solution {
public:
    vector<vector<string>> ans;
    int n;
    bool isPalindrome(string s, int left,int right)
    {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    void solve(string &s, int idx, vector<string> &curr)
    {
        if(idx==n)
        {
            ans.push_back(curr);
            return;
        }
        for(int i=idx;i<n;i++)
        {
            if(isPalindrome(s,idx,i))
            {
                curr.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string> curr;
        solve(s,0,curr);
        return ans;
    }
};