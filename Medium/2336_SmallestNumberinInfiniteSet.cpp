#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repg(i, j, n) for (int i = (int)j; i < (int)(n); i++)
#define repig(i, n, j) for (int i = (int)(n)-1; i >= (int)j; i--)

class SmallestInfiniteSet {
    vector<int> nums;

   public:
    SmallestInfiniteSet() { nums = vector<int>(1001, 1); }

    int popSmallest() {
        int idx = 1;
        repg(i, 1, nums.size()) {
            if (nums[i]) {
                idx = i;
                break;
            }
        }
        nums[idx] = 0;
        return idx;
    }

    void addBack(int num) { nums[num] |= 1; }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
