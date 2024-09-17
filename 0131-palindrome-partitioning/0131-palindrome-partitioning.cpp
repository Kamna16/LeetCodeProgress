class Solution {
public:
    vector<vector<string>> ans;
    bool palindrome(string s, int start, int end)
    {
        while(start <= end)
        {
            if(s[start] != s[end]) return false;

            start++;
            end--;
        }
        return true;
    }
    void solve(string s, vector<string> &curr, int idx)
    {
        if(idx == s.size())
        {
            ans.push_back(curr);
            return;
        }

        for(int i=idx;i<s.size();i++)
        {
            if(palindrome(s,idx,i)){
                string str = s.substr(idx,i-idx+1);
                curr.push_back(str);
                solve(s,curr,i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        solve(s,curr,0);
        return ans;
    }
};