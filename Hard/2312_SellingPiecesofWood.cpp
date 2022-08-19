#include <bits/stdc++.h>
using namespace std;

/*
  dp[i][j]=i*jマスの木を得る時の最大の稼ぎ
  メモ化再帰が実装しやすいと思う。
*/
class Solution {
    long long dp[201][201];

    long long calcPrice(int m, int n, vector<vector<long long>>& pr) {
        if (m == 1 && n == 1) return dp[1][1];

        for (int i = 1; i < m; i++) {
            if (dp[i][n] == -1) dp[i][n] = calcPrice(i, n, pr);
            if (dp[m - i][n] == -1) dp[m - i][n] = calcPrice(m - i, n, pr);
            dp[m][n] = max(dp[m][n], dp[i][n] + dp[m - i][n]);
        }
        for (int j = 1; j < n; j++) {
            if (dp[m][j] == -1) dp[m][j] = calcPrice(m, j, pr);
            if (dp[m][n - j] == -1) dp[m][n - j] = calcPrice(m, n - j, pr);
            dp[m][n] = max(dp[m][n], dp[m][j] + dp[m][n - j]);
        }
        return dp[m][n] = max(dp[m][n], pr[m][n]);
    }

   public:
    Solution() { memset(dp, -1, sizeof(dp)); }

    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> pr(201, vector<long long>(201, 0));
        for (int i = 0; i < prices.size(); i++) {
            pr[prices[i][0]][prices[i][1]] = (long long)prices[i][2];
        }

        dp[1][1] = pr[1][1];
        return calcPrice(m, n, pr);
    }
};
