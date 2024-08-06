class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26,0);
        for(char ch : word)
        {
            mp[ch-'a']++;
        }
        sort(mp.begin(),mp.end(),greater<int>());
        int sum =0;
        for(int i=0;i<26;i++)
        {
            int freq = mp[i];
            int press = i/8+1;
            sum+= press * freq;
        }
        return sum;
    }
};