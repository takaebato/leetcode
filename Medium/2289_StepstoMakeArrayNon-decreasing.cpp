#include <bits/stdc++.h>
using namespace std;

/*
  DPらしいけど分からん
*/
class Solution {
   public:
    int totalSteps(vector<int>& nums) {
        int ans = 0;
        int idx = 0;
        while (idx < nums.size()) {
            int val = nums[idx];
            int t = 1;
            int cnt = 0;
            while (val > nums[idx + t] && t < nums.size() - idx) {
                if (t == 1) {
                    cnt++;
                    t++;
                    continue;
                }
                if (nums[idx + t - 1] > nums[idx + t]) {
                    t++;
                    continue;
                } else if (nums[idx + t - 1] == nums[idx + t]) {
                    cnt++;
                    t++;
                    continue;
                } else {
                    ans = max(ans, cnt);
                    cnt = 0;
                    t++;
                    continue;
                }
            }
            ans = max(ans, cnt);
            idx += t;
        }
        return ans;
    }
};
