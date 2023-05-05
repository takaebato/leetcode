#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, j, n) for (int i = (int)(n)-1; i >= (int)j; i--)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    int m, n;

    void calcSpiral(int c, ListNode* head, vector<vector<int>>& sp) {
        int cm = m - c;
        int cn = n - c;

        repg(i, c, cn - 1) {
            if (head == nullptr) break;
            sp[c][i] = head->val;
            head = head->next;
        }
        repg(i, c, cm - 1) {
            if (head == nullptr) break;
            sp[i][cn - 1] = head->val;
            head = head->next;
        }
        repig(i, c + 1, cn) {
            if (head == nullptr) break;
            sp[cm - 1][i] = head->val;
            head = head->next;
        }
        repig(i, c + 1, cm) {
            if (head == nullptr) break;
            sp[i][c] = head->val;
            head = head->next;
        }
        if (head != nullptr) calcSpiral(c + 1, head, sp);
    }

   public:
    vector<vector<int>> spiralMatrix(int im, int in, ListNode* head) {
        m = im, n = in;
        vector<vector<int>> sp(m, vector<int>(n, -1));
        if (m == 1 && n == 1) {
            sp[0][0] = head->val;
            return sp;
        }
        calcSpiral(0, head, sp);
        return sp;
    }
};
