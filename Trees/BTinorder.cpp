#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> InorderTraversal;
    void inorder(TreeNode* root)
    {
        if(root == NULL) return;
        inorder(root->left);
        InorderTraversal.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return InorderTraversal;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr!= NULL || !st.empty())
        {
            while(curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }
};