class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> mp;
        set<int> st(arr.begin(),arr.end());
        int rank =1;
        for(int num : st)
        {
            mp[num] = rank;
            rank++;
        }
        for(int i=0;i<arr.size();i++)
        {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};