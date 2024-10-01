class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> mp(k,0);
        for(int i=0;i<n;i++)
        {
            int rem = (arr[i]%k + k)%k;
            mp[rem]++;
        }
        int count =0;
        if(mp[0]%2 != 0) return false;
        for(int i=1;i<=k/2;i++)
        {
            int Find = k - i;
            if(mp[Find] != mp[i]) return false;
        }
        return true;
    }
};