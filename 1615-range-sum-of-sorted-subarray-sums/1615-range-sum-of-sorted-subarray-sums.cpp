class Solution {
public:
    #define mod 1000000007
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            int sum = 0;
            for(int j=i;j<n;j++)
            {
                sum+= nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(), v.end());
        long long sum =0;
        for(int i=left-1;i<=right-1;i++)
        {
            sum+= v[i];
        }
        return sum%mod;
    }
};