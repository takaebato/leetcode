#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minMaxGame(vector<int>& nums) { return calcNew(nums); }

   private:
    int calcNew(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> newNums(nums.size() / 2);
        for (int i = 0; newNums.size(); i++) {
            if (i % 2 == 0)
                newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
            else
                newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
        }
        return calcNew(newNums);
    }
};
