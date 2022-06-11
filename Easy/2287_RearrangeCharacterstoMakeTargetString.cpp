#include <bits/stdc++.h>
using namespace std;

class Solution {
    auto getCount(const string &s) {
        array<int, 26> ret = {{0}};
        for (auto c : s) {
            ret[c - 'a']++;
        }
        return ret;
    }

   public:
    int rearrangeCharacters(string s, string target) {
        auto f = getCount(s);
        auto t = getCount(target);

        int c = 1e9;
        for (int i = 0; i < 26; i++) {
            if (t[i] > 0) c = min(c, f[i] / t[i]);
        }
        return c;
    }
};
