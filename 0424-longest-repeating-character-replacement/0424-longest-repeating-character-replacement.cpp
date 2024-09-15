class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> mp(26,0);
        int len =0, maxfreq=0;
        int l=0,r=0;
        while(r<n)
        {
            mp[s[r] -'A']++;
            maxfreq = max(maxfreq, mp[s[r] - 'A']);
            while((r-l+1) - maxfreq > k)
            {
                mp[s[l]-'A']--;
                maxfreq =0;
                for(int f : mp)
                {
                    maxfreq = max(maxfreq, f);
                }
                l++;
            }
            if((r-l+1) - maxfreq <= k)
            {
                len = max(len, r-l+1);
            }
            r++;
        }
        return len;

    }
};