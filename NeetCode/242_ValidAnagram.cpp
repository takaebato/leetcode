#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

/*
  vectorを用いた場合。
  アルファベットの場合は'a'との差分で数字に変換した方がシンプルかつ効率的かもしれない。
  ハッシュマップを使うと、findで探索するコストがかかる。
*/
class Solution {
   public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        for (char c : t) cnt[c - 'a']--;
        rep(i, 26) if (cnt[i] != 0) return false;

        return true;
    }
};

/*
  ハッシュマップを用いた場合。
*/
class Solution {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for (char c : s) {
            if (mp.find(c) == mp.end()) mp[c] = 0;
            mp[c]++;
        }
        for (char c : t) {
            if (mp.find(c) == mp.end()) return false;
            mp[c]--;
        }
        for (auto p : mp) {
            if (p.second != 0) return false;
        }

        return true;
    }
};
