#include<bits/stdc++.h>
using namespace std;

// Brute Force
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            int sum = 0;
            for(int j=i;j<n;j++)
            {
                sum+= nums[j];
                if(sum == k) count++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
		mp[0] = 1;
		int Sum = 0, count =0;
		for(int i=0; i< nums.size();i++)
		{
			Sum += nums[i];
			int remove = Sum -k;
			count +=  mp[remove];
			mp[Sum] +=1;
		}
		return count;
    }
};