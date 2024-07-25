/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recur(vector<int>& nums, int start, int end)
    {
        if(start > end) return NULL;
        int mid = (start + end)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = recur(nums, start, mid-1);
        root->right = recur(nums, mid+1, end);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return recur(nums, 0, n-1);
    }
};