class NumArray {
public:
    vector<int> nums;
    vector<int> PrefixSum;

    NumArray(vector<int>& nums) : nums(nums) {
        PrefixSum.resize(nums.size() + 1); 
        PrefixSum[0] = 0; 
        for (int i = 0; i < nums.size(); i++) {
            PrefixSum[i + 1] = PrefixSum[i] + nums[i];
        }
    }
    
    void update(int index, int val) {
        int diff = val - nums[index]; 
        nums[index] = val; 
        
        for (int i = index + 1; i < PrefixSum.size(); i++) {
            PrefixSum[i] += diff;
        }
    }
    
    int sumRange(int left, int right) {
        return PrefixSum[right + 1] - PrefixSum[left]; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */