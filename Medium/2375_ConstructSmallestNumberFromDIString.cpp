#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

class Solution {
   public:
    string smallestNumber(string pattern) {
        const int n = pattern.length() + 1;
        vector<int> nums(n);
        rep(i, n) nums[i] = i + 1;
        ll minNum = LLONG_MAX;
        do {
            bool ok = true;
            rep(i, n - 1) {
                if (pattern[i] == 'D') {
                    if (nums[i] < nums[i + 1]) ok = false;
                } else {
                    if (nums[i] > nums[i + 1]) ok = false;
                }
            }
            if (ok) {
                ll num = 0;
                rep(i, n) num = num * 10 + nums[i];
                minNum = min(minNum, num);
            }
        } while (next_permutation(nums.begin(), nums.end()));
        return to_string(minNum);
    }
};
