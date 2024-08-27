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

class BSTIterator {
public:
    vector<int> inorder;
    int currentIndex;

    void store(TreeNode* root) {
        if(!root) return;
        store(root->left);
        inorder.push_back(root->val);
        store(root->right);
    }

    BSTIterator(TreeNode* root) {
        store(root);
        currentIndex = 0; 
    }
    
    int next() {
        return inorder[currentIndex++];
    }
    
    bool hasNext() {
        return currentIndex < inorder.size(); 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */