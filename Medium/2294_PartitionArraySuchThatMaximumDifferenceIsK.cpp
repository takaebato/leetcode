#include <bits/stdc++.h>
using namespace std;

/*
  単純なGreedyで行けた
*/
class Solution {
   public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int min = -1e6;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - min > k) {
                cnt++;
                min = nums[i];
            }
        }
        return cnt;
    }
};
