#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

class Solution {
   public:
    string largestPalindromic(string num) {
        vector<int> pali;
        vector<int> judge(10, 0);
        for (char c : num) {
            if (judge[c - '0'] == 0) {
                judge[c - '0']++;
            } else {
                pali.push_back(c - '0');
                judge[c - '0'] = 0;
            }
        }
        int max_rem = -1;
        rep(i, 10) if (judge[i]) max_rem = i;

        bool is_all_zero = true;
        rep(i, pali.size()) if (pali[i] != 0) is_all_zero = false;
        if (is_all_zero) {
            if (max_rem != -1) {
                return to_string(max_rem);
            } else {
                return "0";
            }
        }

        sort(pali.begin(), pali.end(), std::greater<int>());

        string ans;
        rep(i, pali.size()) ans += to_string(pali[i]);
        if (max_rem != -1) ans += to_string(max_rem);
        repig(i, pali.size(), 0) ans += to_string(pali[i]);
        return ans;
    }
};
