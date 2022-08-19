#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)

class Solution {
   public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;
        int idx = 0;
        for (auto k : key) {
            if (k == ' ' || mp.find(k) != mp.end()) continue;

            mp[k] = char('a' + idx);
            idx++;
        }
        for (auto &c : message) if (c != ' ') c = mp[c];
        return message;
    }
};
