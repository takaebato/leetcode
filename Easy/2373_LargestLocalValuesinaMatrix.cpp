#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

// (n-2)*(n-2)*3*3
class Solution {
   public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int range[3] = {-1, 0, 1};
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2, 0));
        rep(i, n - 2) {
            rep(j, n - 2) {
                for (int x : range) {
                    for (int y : range) {
                        maxLocal[i][j] = max(maxLocal[i][j], grid[i + 1 + x][j + 1 + y]);
                    }
                }
            }
        }
        return maxLocal;
    }
};
