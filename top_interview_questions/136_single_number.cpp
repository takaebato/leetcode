#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

// 正解のbit manipulation は激ムズだけど面白い. bit演算の並び替えても同値の性質など。
// ただこれが使えたのは、一つだけが例外だったからかもしれない。
class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        rep(i, nums.size()) { a ^= nums[i]; }
        return a;
    }
};

// メモリO(N)だからダメではある
class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        map<int, int> count;
        rep(i, nums.size()) {
            if (count.find(nums[i]) != count.end()) {
                count[nums[i]]++;
            } else {
                count[nums[i]] = 0;
            }
        }
        rep(i, nums.size()) {
            if (count[nums[i]] == 0) {
                return nums[i];
            }
        }
        return 0;
    }
};
