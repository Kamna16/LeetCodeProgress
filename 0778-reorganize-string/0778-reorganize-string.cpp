class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        for(auto ch : s)
        {
            mp[ch]++;
            if(mp[ch] > (n+1)/2) return "";
        }
        for(auto p : mp)
        {
            pq.push({p.second,p.first});
        }
        string result = "";
        while(pq.size() >= 2)
        {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();

            result.push_back(p1.second);
            result.push_back(p2.second);
            p1.first -= 1;
            p2.first -= 1;
            if(p1.first >=1) pq.push(p1);
            if(p2.first >=1) pq.push(p2);
        }
        if(!pq.empty()) result.push_back(pq.top().second);
        return result;
    }
};