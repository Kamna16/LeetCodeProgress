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
    vector<string> ans;
    void dfs(TreeNode* root, string temp)
    {
        if (!root) return;

        if (!temp.empty()) {
            temp += "->";
        }
        temp += to_string(root->val);

        if (!root->left && !root->right) {
            ans.push_back(temp);
            return;
        }

        dfs(root->left, temp);
        dfs(root->right, temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return ans;
    }
};