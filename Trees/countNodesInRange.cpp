#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
      if(!root) return 0;
      
      int left = getCount(root->left,l,h);
      int right = getCount(root->right,l,h);
      if(root->data >= l && root->data <= h)
      {
          return 1 + left + right;
      }
      return left + right;
    }
};