#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int studentsAllocated(int maxPages, int arr[], int n)
    {
        int students=1;
        int pagesAllocated = 0;
        for(int i=0;i<n;i++)
        {
            if(pagesAllocated+arr[i] <= maxPages) pagesAllocated+= arr[i];
            else{
                students++;
                pagesAllocated = arr[i];
            }
        }
        return students;
    }
    long long findPages(int n, int arr[], int m) {
        if(m>n) return -1;
        int lowest = 0;
        int highest = 0;
        for(int i=0;i<n;i++)
        {
            lowest = max(lowest, arr[i]);
            highest += arr[i];
        }
        while(lowest <= highest)
        {
            int mid = lowest +(highest-lowest)/2;
            int noOfStudents = studentsAllocated(mid,arr,n);
            if(noOfStudents > m) lowest = mid+1;
            else highest = mid-1;
        }
        return lowest;
    }
};
