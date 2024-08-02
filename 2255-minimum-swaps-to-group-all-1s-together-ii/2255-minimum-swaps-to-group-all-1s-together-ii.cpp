#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int oneCount = 0;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) oneCount++;
        }

        if (oneCount == 0 || oneCount == n) return 0;

        nums.insert(nums.end(), nums.begin(), nums.end());

        int zeroCount = 0;
        for(int i = 0; i < oneCount; i++) {
            if(nums[i] == 0) zeroCount++;
        }

        int minSwaps = zeroCount;
        for(int i = oneCount; i < 2 * n; i++) {
            if(nums[i - oneCount] == 0) zeroCount--; 
            if(nums[i] == 0) zeroCount++;
            minSwaps = min(minSwaps, zeroCount);
        }

        return minSwaps;
    }
};
