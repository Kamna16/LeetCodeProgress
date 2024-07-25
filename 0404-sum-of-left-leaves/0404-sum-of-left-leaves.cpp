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
    int sum =0;
    void solve(TreeNode* root, TreeNode* parent)
    {
        if(!root) return;

        if(root->left == NULL && root->right == NULL)
        {
            if(parent != NULL && parent->left == root)
            {
                sum+= root->val;
            }
        }
        solve(root->left,root);
        solve(root->right,root);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        solve(root,NULL);
        return sum;
    }
};