#include<bits/stdc++.h>
using namespace std;

//1) using extra space --> map
//2) using sorting
//3) using 3 pointers
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int k=0;
        int j=n-1;
        while(k<=j){
            if(nums[k]==2)
            {
                swap(nums[k],nums[j]);
                j--;
            }
            else if(nums[k]==0)
            {
                swap(nums[k],nums[i]);
                k++;
                i++;
            }else k++;
        }
    }
};