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
    int count=0;
    void sum(TreeNode* root, int low, int high)
    {
        if(root == NULL) return;

        sum(root->left,low,high);
        if(root->val >= low && root->val <= high) count += root->val;
        sum(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum(root,low,high);
        return count;
    }
};