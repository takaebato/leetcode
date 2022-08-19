#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0;
        if (income > brackets[0][0]) {
            ans += brackets[0][0] * brackets[0][1] * 0.01;
        } else {
            ans += income * brackets[0][1] * 0.01;
            return ans;
        }

        int idx = 1;
        while (1) {
            if (income > brackets[idx][0]) {
                ans += (brackets[idx][0] - brackets[idx - 1][0]) * brackets[idx][1] * 0.01;
                idx++;
            } else {
                ans += (income - brackets[idx - 1][0]) * brackets[idx][1] * 0.01;
                break;
            }
        }

        return ans;
    }
};
