#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

/*
  考察、問題の置き換え。
  startからtargetを作れるかどうか？ <=> L,Rの順序が同じ、かつ、各L,Rがそれぞれstartのindex以下、以上になっていること
*/
class Solution {
   public:
    bool canChange(string start, string target) {
        const int ns = start.size();
        const int nt = target.size();
        if (ns != nt) return false;

        int ids = 0, idt = 0;
        bool ok = true;
        while (1) {
            while (ids < ns && start[ids] == '_') ids++;
            while (idt < nt && target[idt] == '_') idt++;
            if (ns <= ids || nt <= idt) break;

            if (start[ids] != target[idt]) {
                ok = false;
            } else if (start[ids] == 'L' && ids < idt) {
                ok = false;
            } else if (start[ids] == 'R' && ids > idt) {
                ok = false;
            }
            ids++, idt++;
        }
        if (ids != ns || idt != nt) ok = false;
        return ok;
    }
};
