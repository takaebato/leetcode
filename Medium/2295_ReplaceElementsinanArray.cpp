#include <bits/stdc++.h>
using namespace std;

/*
  クエリ問題。
  n,m<=1e5, 単純な線形探索では無理。
  順序は保持したいからsortで二分探索はやめた方がいいか。
  前処理として、index保持の配列を用意して、探索と更新をO(1)で終わらせられそう。
*/
class Solution {
   public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        vector<int> idx(1e6 + 1, -1);
        for (int i = 0; i < nums.size(); i++) {
            idx[nums[i]] = i;
        }
        for (int i = 0; i < operations.size(); i++) {
            int id = idx[operations[i][0]];
            nums[id] = operations[i][1];
            idx[operations[i][1]] = id;
        }
        return nums;
    }
};
