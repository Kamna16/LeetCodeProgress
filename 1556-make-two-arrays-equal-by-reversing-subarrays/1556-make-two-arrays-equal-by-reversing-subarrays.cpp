class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int i : arr)
        {
            freq[i]++;
        }
        for(int i : target)
        {
            freq[i]--;
        }
        for(auto p : freq)
        {
            if(p.second >= 1) return false;
        }
        return true;
    }
};