#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)


// // 並び替えて隣の要素が同じか確認する。メモリは食わないが、sortする分遅い。
// class Solution {
//    public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         rep1(i, nums.size()) {
//             if (nums[i] == nums[i - 1]) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

// 出て来た要素をキーとしてHashに格納するド典型のやり方。メモリ食う。
class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> count;
        rep(i, nums.size()) {
            if (count.find(nums[i]) != count.end()) {
                return true;
            } else {
                count[nums[i]] = 0;
            }
        }
        return false;
    }
};
