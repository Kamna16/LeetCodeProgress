class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 1) return 1;
        int i=0;
        int maxi = 0;
        unordered_map<char,int> mp;
        for(int j=0;j<n;j++)
        {
            if(mp.find(s[j]) != mp.end())
            {
                maxi = max(maxi, j-i);
                i = j;
                mp.clear();
                mp[s[j]]++;
            }
            else{
                mp[s[j]]++;
                maxi = max(maxi, j-i);
            }
        }
        return maxi;
    }
};