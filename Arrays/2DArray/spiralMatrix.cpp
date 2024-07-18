#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 0 || n == 0) return {};
         vector<int> ans;
         int top=0, left=0, right=n-1, bottom=m-1;
         while(left <= right && top <= bottom){

            for(int i=left;i<=right;i++)
            {
                ans.push_back(matrix[top][i]);
            }top++;

            for(int i=top;i<=bottom;i++)
            {
                ans.push_back(matrix[i][right]);
            }right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
         }
         return ans;
    }
};