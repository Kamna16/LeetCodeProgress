class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        string token = "";
        stringstream ss1(s1);
        stringstream ss2(s2);
        while(getline(ss1,token,' '))
        {
            mp[token]++;
        }
        while(getline(ss2,token,' '))
        {
            mp[token]++;
        }
        vector<string> ans;
        for(auto p : mp)
        {
            if(p.second == 1)
            {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};