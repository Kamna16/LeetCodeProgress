#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int sr,int sc, vector<vector<int>>& image, int color, int iniColor,int n,int m) {
        if (sr < 0 || sc < 0 || sr >= n || sc >= m || image[sr][sc] != iniColor) {
            return;
        }
        
        image[sr][sc] = color;

        dfs (sr+ 1, sc, image, color, iniColor, n, m); // Down
        dfs(sr - 1, sc, image, color, iniColor, n, m); // Up
        dfs(sr, sc + 1, image, color, iniColor, n, m); // Right
        dfs(sr, sc - 1, image, color, iniColor, n, m); // Left
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> temp = image;
        int iniColor= image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        if(iniColor == color) return image;
        dfs(sr,sc,temp,color,iniColor,n,m);
        return temp;
    }
};