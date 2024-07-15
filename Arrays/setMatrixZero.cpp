#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n, 0); 
        vector<int> col(m, 0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(row[i]==1 || col[j]==1)
                {
                    matrix[i][j] =0;
                }
            }
        }
    }
};

// optimizing space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0]=0;
                    if(j==0)
                    {
                        col0 = 0;
                    }else matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
               if(matrix[0][j]==0 || matrix[i][0]==0)
                    {
                        matrix[i][j] =0;
                    }
            }
        }
        if(matrix[0][0] == 0)
        {
            for(int j=0;j<m;j++) matrix[0][j] = 0;
        }
        if(col0 == 0)
        {
            for(int i=0;i<n;i++) matrix[i][0] = 0;
        }
    }
};