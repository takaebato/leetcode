#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

/*
  DAG.
  DPだった。ヒント見た。
  dp[i][j]: ノード(i,j)におけるパスの数.
  メモ化再帰の実装がやりやすいか。
  ちなみにグリッドグラフでなくとも同じやり方で解ける。
*/
class Solution {
    const int MOD = 1e9 + 7;
    const int dy[4] = {1, 0, 0, -1};
    const int dx[4] = {0, -1, 1, 0};
    int h, v;

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, int m, int n) {
        dp[m][n] = 1;
        int x, y;
        rep(i, 4) {
            y = m + dy[i], x = n + dx[i];
            if (y < 0 || y >= h || x < 0 || x >= v) continue;
            if (grid[y][x] >= grid[m][n]) continue;

            if (dp[y][x] == -1) dp[y][x] = dfs(grid, dp, y, x);
            dp[m][n] = (dp[m][n] + dp[y][x]) % MOD;
        }
        return dp[m][n];
    }

   public:
    int countPaths(vector<vector<int>>& grid) {
        h = grid.size();
        v = grid[0].size();
        vector<vector<int>> dp(h, vector<int>(v, -1));

        dfs(grid, dp, h, v);

        int ans = 0;
        rep(i, h) rep(j, v) ans = (ans + dp[i][j]) % MOD;
        return ans;
    }
};
