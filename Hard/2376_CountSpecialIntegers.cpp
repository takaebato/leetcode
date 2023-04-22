#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

class Solution {
   public:
    int countSpecialNumbers(int n) {
        string num = to_string(n);
        const int len = num.length();
        vector<vector<int>> nums(len, vector<int>(10, 0));
        rep(i, 10) if (num[0] - '0' >= i) nums[0][i] = 1;
        rep(i, len-1) {
          rep(j,10){
          rep(k,10){
            if()
          nums[i+1][k]=nums[i][j]

          }



        }
    }
};

/*
  場合分けはキツい。バグとりきれず。
*/
// class Solution {
//     int cnt(int l) {
//         int res = 1;
//         int tmp = 9;
//         rep(i, l) res *= tmp, tmp--;
//         return res;
//     }

//    public:
//     int countSpecialNumbers(int n) {
//         string num = to_string(n);
//         const int len = num.length();
//         int ans = 0;
//         int prev = 10;
//         rep(i, len) {
//             int digit = num[i] - '0';
//             if (prev < digit) {
//                 ans += (max(digit - 2, 0)) * cnt(len - 1 - i);
//             } else {
//                 ans += (max(digit - 1, 0)) * cnt(len - 1 - i);
//             }
//             prev = digit;
//         }
//         return ans;
//     }
// };
