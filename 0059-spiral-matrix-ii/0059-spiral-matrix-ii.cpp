class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n));
        int top = 0;
        int down = n-1;
        int left =0;
        int right = n-1;
        int id =0;
        int cnt = 1;
        while(top<=down && left <= right && cnt <= n*n)
        {
            if(id == 0)
            {
                for(int i=left;i<= right;i++)
                {
                    mat[top][i] = cnt;
                    cnt++;
                }
                top++;
            }
            if(id == 1)
            {
                for(int i=top;i<= down;i++)
                {
                    mat[i][right] = cnt;
                    cnt++;
                }
                right--;
            }
            if(id == 2)
            {
                for(int i=right;i>=left;i--)
                {
                    mat[down][i] = cnt;
                    cnt++;
                }
                down--;
            }
            if(id == 3)
            {
                for(int i=down;i>=top;i--)
                {
                    mat[i][left] = cnt;
                    cnt++;
                }
                left++;
            }
            id = (id+1)%4;
        }    
        return mat;
    }
};