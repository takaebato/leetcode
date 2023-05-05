#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

// n^3
class Solution {
   public:
    int equalPairs(vector<vector<int>>& grid) {
        const int n = grid.size();
        int ans = 0;
        rep(i, n) {
            rep(j, n) {
                bool ok = true;
                rep(k, n) {
                    if (grid[i][k] != grid[k][j]) ok = false;
                }
                if (ok) ans++;
            }
        }
        return ans;
    }
};

// n^2 + mem(n)
class Solution {
   public:
    int equalPairs(vector<vector<int>>& grid) {
        const int n = grid.size();
        map<vector<int>, int> mp;
        rep(i, n) mp[grid[i]]++;
        vector<int> v(n);

        int ans = 0;
        rep(i, n) {
            rep(j, n) v[j] = grid[j][i];
            ans += mp[v];
        }

        return ans;
    }
};
