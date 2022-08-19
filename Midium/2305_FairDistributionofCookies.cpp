#include <bits/stdc++.h>
using namespace std;

/*
  いくつかのクッキーが入ったn個の袋をk人に配って一人当たりの最大数を出来るだけ減らす。
  愚直ではk^n. n<=8, k<=8 で、この制約なら2^24=10^7くらいでいける。
*/
class Solution {
   public:
    int distributeCookies(vector<int>& cookies, int k) {
        int ans = 1e8;
        dfs(cookies, 0);
    }

   private:
    int dfs(vector<int>& cookies, int depth) {
        if(depth==7)
        for (int i = 0; i < cookies.size(); i++) {
            dfs(cookies, ++depth);
        }
    }
};
