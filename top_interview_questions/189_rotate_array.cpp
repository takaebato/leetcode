#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define repr1(i, n) for (int i = (int)(n)-1; i > 0; i--)

// cyclicの解き方はかなりむずい

// in place この問題特有のテクニック感はある
class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        while (k > size) {
            k -= size;
        }
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// // N*k TLE 10**10
// class Solution {
//    public:
//     void rotate(vector<int>& nums, int k) {
//         int size = nums.size();
//         while (k > size) {
//             k -= size;
//         }
//         rep(i, k) { rotate1(nums); }
//     }

//    private:
//     void rotate1(vector<int>& nums) {
//         int tmp = nums[nums.size() - 1];
//         repr1(i, nums.size()) { nums[i] = nums[i - 1]; }
//         nums[0] = tmp;
//     }
// };

// //  Copy array
// class Solution {
//    public:
//     void rotate(vector<int>& nums, int k) {
//         int size = nums.size();
//         while (k > size) {
//             k -= size;
//         }
//         vector<int> copyNums(nums);
//         rep(i, size) {
//             if (i + k < size) {
//                 nums[i + k] = copyNums[i];
//             } else {
//                 nums[i + k - size] = copyNums[i];
//             }
//         }
//     }
// };
