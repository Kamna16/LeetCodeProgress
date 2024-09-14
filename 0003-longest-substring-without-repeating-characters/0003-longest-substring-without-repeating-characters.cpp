class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int n = s.size();
        vector<char> ex;
        int count =0;
        for(int i=0;i<n;i++)
        {
            auto it = find(ex.begin(), ex.end(), s[i]);
            if(it == ex.end())
            {
                ex.push_back(s[i]);
                count++;
            }
            else{
                ex.erase(ex.begin(), it + 1);
                ex.push_back(s[i]);
                count = ex.size();
            }
            ans= max(ans,count);
        }
        return ans;
    }
};