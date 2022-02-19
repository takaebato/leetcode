#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

class Solution {
   public:
    int removeDuplicates(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        } else if (len == 1) {
            return 1;
        }

        int i = 0;
        rep1(j, len) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main() {
    vector<int> nums{1, 2, 3, 3, 3, 5, 6, 6, 7};
    Solution s;
    int k = s.removeDuplicates(nums);
    cout << k << endl;
    rep(i, nums.size()) { cout << nums[i] << ","; }
    return 0;
}
