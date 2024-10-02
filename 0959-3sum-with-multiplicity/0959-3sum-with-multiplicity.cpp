class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int num : arr)
        {
            mp[num]++;
        }
        long long count =0;
        int mod = 1e9 +7;
        for(auto p1 : mp)
        {
            for(auto p2 : mp)
            {
                int num1 = p1.first;
                int num2 = p2.first;
                int freq1 = p1.second;
                int freq2 = p2.second;
                int num3 = target - num1 - num2;
                if(!mp.count(num3)) continue;
                int freq3 = mp[num3];
                if(num1 == num2 && num2 == num3)
                {
                    count += (long long)freq1*(freq1-1)*(freq1-2)/6;
                }else if(num1 == num2 && num2 != num3)
                {
                    count += (long long)freq1*(freq1-1)/2 * freq3;
                }else if(num1 < num2 && num2 < num3)
                {
                    count += (long long)freq1*freq2*freq3;
                }
            }
            count = count%mod;
        }
            return (int)count;
    }
};