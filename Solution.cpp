#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dfs(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp,
        int i, int j, int m, int n){
        if(i == m || j == n || obstacleGrid[i][j]) return 0;
        if(i == m - 1 && j == n - 1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int d = dfs(obstacleGrid, dp, i + 1, j, m, n);
        int r = dfs(obstacleGrid, dp, i, j + 1, m, n);
        dp[i][j] = d + r;
        return d + r;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int res = dfs(obstacleGrid, dp, 0, 0, m, n);
        return res;
    }
};