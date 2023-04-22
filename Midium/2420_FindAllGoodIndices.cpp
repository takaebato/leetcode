#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

/*
  愚直にやるとO((n-2k)*2k)=O(n^2)
*/
class Solution {
   public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        if (k == 1) {
            vector<int> ans;
            for (int i = k; i < nums.size() - k; i++) {
                ans.push_back(i);
            }
            return ans;
        }
        vector<bool> flag(nums.size(), false);
        int tmp = 1;
        for (int i = 0; i < nums.size() - k - 2; i++) {
            if (nums[i] >= nums[i + 1]) {
                if (tmp >= k) flag[i + 1] = true;
                tmp++;
            } else {
                if (tmp >= k) flag[i + 1] = true;
                tmp = 1;
            }
        }
        tmp = 1;
        for (int i = nums.size() - 1; i > k + 1; i--) {
            if (nums[i - 1] <= nums[i]) {
                if (tmp >= k) flag[i - 1] = true;
                tmp++;
            } else {
                if (tmp >= k) flag[i - 1] = true;
                tmp = 1;
            }
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (flag[i]) ans.push_back(i);
        }
        return ans;
    }
};
