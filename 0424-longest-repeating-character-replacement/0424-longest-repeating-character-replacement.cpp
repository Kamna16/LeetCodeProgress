class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> mp(26,0);
        int maxlen = 0;
        int maxFreq=0;
        int len =0;
        int l=0, r=0;
        while(r<n)
        {
            mp[s[r] - 'A'] += 1;
            maxFreq = max(maxFreq, mp[s[r] - 'A']);

            while((r-l+1) - maxFreq >k)
            {
                mp[s[l]-'A'] -= 1;
                maxFreq = 0;
                for(int i=0;i<26;i++)
                {
                    maxFreq = max(maxFreq, mp[i]);
                }
                l++;
            }
            if((r-l+1) - maxFreq <=k)
            {
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};