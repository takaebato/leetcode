#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string greatestLetter(string s) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);
        for (auto c : s) {
            if (c - 'A' < 26)
                upper[c - 'A']++;
            else
                lower[c - 'a']++;
        }
        int mc = -1;
        for (int i = 0; i < 26; i++) {
            if (lower[i] && upper[i]) mc = i;
        }
        if (mc == -1) return "";
        return string(1, char('A' + mc));
    }
};
