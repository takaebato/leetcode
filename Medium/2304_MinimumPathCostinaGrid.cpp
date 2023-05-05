#include <bits/stdc++.h>
using namespace std;

/*
  dp.
  dp[i][j]=i行目・j列目への到達経路での最小コスト
*/
class Solution {
   public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 1e8));

        for (int i = 0; i < grid[0].size(); i++) dp[0][i] = grid[0][i];

        for (int i = 1; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                for (int k = 0; k < grid[0].size(); k++) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + moveCost[grid[i - 1][k]][j] + grid[i][j]);
                }
            }
        }
        int ans = 1e8;
        for (int i = 0; i < grid[0].size(); i++) ans = min(ans, dp[grid.size() - 1][i]);
        return ans;
    }
};
