#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestSubsequence(string s, int k) {
        if (k == 0) return 0;
        vector<int> w(s.size() + 1, 0);
        int idx = 0;
        for (auto c : s) {
            if (c == '0') w[idx + 1] += w[idx];
        }

        int tmp = k;
        int di = 0;
        while (tmp > 0) {
            tmp = tmp >> 1;
            di++;
        }

        int sum = 0;
        for (int i = 0; i < di; i++) {
            if (s.size() - 1 - i < 0) return s.size();
            sum += ('1' - s[s.size() - 1 - i]) * pow(2, i);
        }

        int t = pow(2, di - 1);
        for (int i = s.size() - 1 - di; i >= 0; i--) {
            sum = sum / 2 + ('1' - s[i]) * t;
        }
    }
};
