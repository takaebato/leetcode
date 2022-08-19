#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

class Solution {
   public:
    int idealArrays(int n, int maxValue) {
        const int MOD = 1e9 + 7;
        vector<int> dp(maxValue + 1, 1);
        repig(i, maxValue + 1, 1) {
            repg(j, 1, i + 1) {
                if (i % j == 0) dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
    }
};
