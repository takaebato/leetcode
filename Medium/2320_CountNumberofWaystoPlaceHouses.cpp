#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)

/*
  まさかのDP。片側だけ考えて、最後に二乗すれば良い。
  dp[i]: i個の家がある場合の、配置の仕方の数
  dp[i+1]=dp[i]+dp[i-1]
*/
class Solution {
   public:
    int countHousePlacements(int n) {
        const int mod = 1e9 + 7;
        if (n == 1) return 2 * 2;
        if (n == 2) return 3 * 3;
        vector<ll> dp(n, 0);
        dp[0] = 2;
        dp[1] = 3;
        repg(i, 2, n) dp[i] = dp[i - 1] + dp[i - 2], dp[i] %= mod;
        return (int)((dp[n - 1] * dp[n - 1]) % mod);
    }
};
