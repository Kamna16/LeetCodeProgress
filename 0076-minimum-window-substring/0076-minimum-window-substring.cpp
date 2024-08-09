class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();

        if(t.size()>n) return "";

        unordered_map<char,int> mp;
        for(auto ch : t)
        {
            mp[ch]++;
        }
        int requiredCount = t.length();
        int i=0,j=0;
        int minWinSize = INT_MAX;
        int start=0;
        while(j<n)
        {
            char ch = s[j];
            if(mp[ch]> 0) requiredCount--;

            mp[ch]--;
            while(requiredCount==0)
            {
                int currWindSize = j-i+1;
                if(minWinSize > currWindSize){
                    minWinSize = currWindSize;
                    start = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0){
                    requiredCount++;
                }
                i++;
            }
            j++; 
        }

        return minWinSize==INT_MAX ? "" : s.substr(start,minWinSize);
    }
};