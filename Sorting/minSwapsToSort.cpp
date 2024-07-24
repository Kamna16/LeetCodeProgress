#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    vector<pair<int,int>> mp;
	    for(int i=0;i<n;i++)
	    {
	        mp.push_back({nums[i],i});
	    }
	    sort(mp.begin(),mp.end());
	    int swaps = 0;
	    for(int i=0;i<n;i++)
	    {
	        int num = mp[i].first;
	        int ind = mp[i].second;
	        if(i != ind){
	            swaps++;
	            swap(mp[i],mp[ind]);
	            i--;
	        }
	    }
	    return swaps;
	}
};