#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

class Solution {
   public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = 0;
        for (int i = 0; i < nums.size(); i++) maxNum = max(maxNum, nums[i]);
        int ans = 0;
        int tmp = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxNum) {
                tmp++;
            } else {
                ans = max(ans, tmp);
                tmp = 0;
            }
        }
        ans = max(ans, tmp);
        return ans;
    }
};
