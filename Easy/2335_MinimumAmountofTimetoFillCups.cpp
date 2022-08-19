#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

class Solution {
   public:
    int fillCups(vector<int>& a) {
        int cnt = 0;
        while (1) {
            sort(a.begin(), a.end());
            if (!a[1] && !a[2]) break;
            if (a[1]) a[1]--;
            if (a[2]) a[2]--;
            cnt++;
        }
        return cnt;
    }
};
