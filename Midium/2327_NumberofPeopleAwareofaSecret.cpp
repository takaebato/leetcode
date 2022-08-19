#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

/*
  愚直なシミュレーション。
  各人の操作は貪欲的に定まる。
*/
class Solution {
   public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> nums(2, vector<int>(forget, 0));
        vector<int> share(2, 0);

        nums[0][0] = 1;
        if (delay - 1 <= 0 && 0 < forget - 1) share[0] = 1;

        repg(i, 1, n) {
            rep(j, forget) {
                if (j == 0) {
                    nums[i & 1][0] = share[(~i) & 1] % MOD;
                    share[(~i) & 1] = 0;
                } else {
                    nums[i & 1][j] = nums[(~i) & 1][j - 1] % MOD;
                }
                if (delay - 1 <= j && j < forget - 1) share[i & 1] = (share[i & 1] + nums[i & 1][j]) % MOD;
            }
        }

        int ans = 0;
        rep(i, forget) ans = (ans + nums[(n - 1) & 1][i]) % MOD;
        return ans;
    }
};
