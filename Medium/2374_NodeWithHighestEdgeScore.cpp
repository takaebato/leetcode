#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

class Solution {
   public:
    int edgeScore(vector<int>& edges) {
        const int n = edges.size();
        vector<ll> score(n, 0);
        rep(i, n) score[edges[i]] += i;
        int idx = n;
        ll ms = 0;
        repig(i, n, 0) {
            if (ms <= score[i]) {
                ms = score[i];
                idx = i;
            }
        }
        return idx;
    }
};
