#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

class Solution {
   public:
    char repeatedCharacter(string s) {
        vector<int> chars(26, 0);
        char ans;
        for (char c : s) {
            if (chars[c - 'a']) {
                ans = c;
                break;
            }
            chars[c - 'a']++;
        }
        return ans;
    }
};
