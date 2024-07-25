#include<bits/stdc++.h>
using namespace std;

void dfs(struct Node *root,vector<int> &inorder)
{
    if(!root) return;
    
    dfs(root->left,inorder);
    inorder.push_back(root->data);
    dfs(root->right,inorder);
}
float findMedian(struct Node *root)
{
    vector<int> inorder;
    dfs(root,inorder);
    int n = inorder.size();
    if (n == 0) return 0.0;
    float mid = 0.0;
    if (n % 2 == 0)
    {
        
        return (inorder[n / 2 - 1] + inorder[n / 2]) / 2.0;
    }
    else
    {
        return inorder[n / 2];
    }
    return mid;
}
