#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)

/*
  n<=1000 だから、2重ループはできる。
  愚直だと、nC2の切り分け方に対し、XOR計算で線形Nかかる。
  このXOR計算を高速化できないか？
  XORは累積和や区間和で良く使われる。XORは2回で元の値に戻るから演算はシンプル。
  今回は、部分木ごとのXORの和を求めておけばいけそう。子ノードのXOR和を親ノードへ送ればいい。帰りがけでXOR和をとっていく。
*/
class Solution {
    vector<int> sum;
    vector<vector<int>> graph;
    vector<vector<int>> des;

    void dfs(vector<int>& nums, int v, int p = -1) {
        sum[v] = nums[v];
        des[v].push_back(v);

        for (auto nv : graph[v]) {
            if (sum[nv] != -1) continue;
            dfs(nums, nv, v);
        }
        if (p != -1) {
            sum[p] ^= nums[v];
            copy(des[v].begin(), des[v].end(), back_inserter(des[p]));
        }
    }

   public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        const int n = nums.size();

        sum.resize(n, -1);
        graph.resize(n);
        des.resize(n);
        rep(i, n - 1) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(nums, 0);
        rep(i, n) sort(des[i].begin(), des[i].end());

        rep(i, graph[0].size()) cout << graph[0][i] << endl;

        int ans = INT_MAX;
        rep(i, n - 1) {
            int a1 = edges[i][0];
            int b1 = edges[i][1];
            int p1;
            if (binary_search(des[a1].begin(), des[a1].end(), b1))
                p1 = a1;
            else
                p1 = b1;
            repg(j, i + 1, n - 1) {
                int a2 = edges[j][0];
                int b2 = edges[j][1];
                int p2;
                if (binary_search(des[a2].begin(), des[a2].end(), b2))
                    p2 = a2;
                else
                    p2 = b2;

                int sum1, sum2, sum3;
                if (binary_search(des[p1].begin(), des[p1].end(), p2)) {
                    sum1 = sum[p1] ^ sum[p2];
                    sum2 = sum[p2];
                    sum3 = sum[0] ^ sum1 ^ sum2;
                } else if (binary_search(des[p2].begin(), des[p2].end(), p1)) {
                    sum1 = sum[p1];
                    sum2 = sum[p2] ^ sum[p1];
                    sum3 = sum[0] ^ sum1 ^ sum2;
                } else {
                    sum1 = sum[p1];
                    sum2 = sum[p2];
                    sum3 = sum[0] ^ sum1 ^ sum2;
                }
                int ma = max({sum1, sum2, sum3});
                int mi = min({sum1, sum2, sum3});
                ans = min(ans, ma - mi);
            }
        }
        return ans;
    }
};
