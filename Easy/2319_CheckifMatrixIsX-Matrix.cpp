#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

class Solution {
   public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        const int n = grid.size();
        rep(i, n) {
            rep(j, n) {
                if (j == i || j == n - 1 - i) {
                    if (!grid[i][j]) return false;
                } else {
                    if (grid[i][j]) return false;
                }
            }
        }
        return true;
    }
};
