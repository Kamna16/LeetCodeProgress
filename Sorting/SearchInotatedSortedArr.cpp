#include<bits/stdc++.h>
using namespace std;

// method 1
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0;
        int h=n-1;
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(nums[mid]==target) return mid;
            //left sorted
            else if(nums[l]<=nums[mid])
            {
                if(target>=nums[l] && target<=nums[mid])
                {
                    h=mid-1;
                }else l=mid+1;
            }else{
                if(target>=nums[mid] && target<=nums[h])
                {
                    l=mid+1;
                }else h=mid-1;
            }
        }
        return -1;
    }
};

// method 2
class Solution {
public:
    int findPivot(vector<int>& nums)
    {
        int start = 0;
        int end= nums.size()-1;
        while(start <= end)
        { 
            int mid = start +(end - start)/2;
            // 4 cases
            if(mid < end && nums[mid] > nums[mid +1]) return mid;
            if(mid > start && nums[mid] < nums[mid-1]) return mid-1;
            if(nums[mid] < nums[start]) end = mid-1;
            else{
                start = mid+1;
            }
        }
        return -1;
    }
    int binarySearch(vector<int>& arr,int target, int s, int e)
    {
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(arr[mid] == target) return mid;
            else if(arr[mid] < target)
            {
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        // case 1
        if(pivot == -1)
        {
            // normal binary search
             return binarySearch(nums, target, 0 , nums.size()-1);
        }
        // case 2
        if(nums[pivot] == target) return pivot;
        // case 3
        if(target >= nums[0])
        {
            return binarySearch(nums,target,0, pivot-1);
        }
        return binarySearch(nums,target,pivot+1,nums.size()-1);
    }
};