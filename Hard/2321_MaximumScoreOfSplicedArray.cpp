#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)

/*
  N<=10^5
  区間を全探索してmaxの判定をすると、N^2*NでO(N^3)
  区間和の計算を累積和を使ってO(1)で済ませても、結局区間の全探索でO(N^2)かかる。
  区間の全探索が出来ない以上、発想の転換が必要。
  DPで上手く遷移を考えればO(N)で行ける。

  漸化式は欲しい部分問題を考えるのがコツ。
  右端が区間に含まれるか否かによって、状態遷移が変わり、さらにどこもswapしないケースも考える必要あり。
  このあたりの問題特有の条件は、その場であり得る遷移ケースを考えるしかない。
*/
class Solution {
   public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size();
        vector<vector<int>> dp1(n, vector<int>(3, 0));
        vector<vector<int>> dp2(n, vector<int>(3, 0));
        dp1[0][0] = nums1[0];
        dp1[0][1] = nums2[0];
        dp1[0][2] = nums1[0];
        dp2[0][0] = nums2[0];
        dp2[0][1] = nums1[0];
        dp2[0][2] = nums2[0];

        repg(i, 1, n) {
            dp1[i][0] = max(dp1[i - 1][0], dp1[i - 1][1]) + nums1[i];
            dp1[i][1] = max(dp1[i - 1][1], dp1[i - 1][2]) + nums2[i];
            dp1[i][2] = dp1[i - 1][2] + nums1[i];
            dp2[i][0] = max(dp2[i - 1][0], dp2[i - 1][1]) + nums2[i];
            dp2[i][1] = max(dp2[i - 1][1], dp2[i - 1][2]) + nums1[i];
            dp2[i][2] = dp2[i - 1][2] + nums2[i];
        }

        return max({dp1[n - 1][0], dp1[n - 1][1], dp1[n - 1][2], dp2[n - 1][0], dp2[n - 1][1], dp2[n - 1][2]});
    }
};
