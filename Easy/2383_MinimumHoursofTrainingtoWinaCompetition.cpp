#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

class Solution {
   public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        const int n = energy.size();
        int ene_hours = 0;
        rep(i, n) ene_hours += energy[i];
        ene_hours = max(0, ene_hours - initialEnergy + 1);

        int exp_hours = 0;
        int max_diff = 0;
        int current_exp = 0;
        rep(i, n) {
            max_diff = max(max_diff, experience[i] - current_exp);
            current_exp += experience[i];
        }
        exp_hours = max(exp_hours, max_diff - initialExperience + 1);

        return ene_hours + exp_hours;
    }
};
