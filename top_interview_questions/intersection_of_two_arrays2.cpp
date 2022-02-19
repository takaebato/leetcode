#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

// two pointersで行けたよ...



// binary search
class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        rep(i, nums1.size()) {
            if (!binary_search(nums2.begin(), nums2.end(), nums1[i])) {
                continue;
            }
            auto it = lower_bound(nums2.begin(), nums2.end(), nums1[i]);
            ans.push_back(nums1[i]);
            nums2.erase(it);
        }
        return ans;
    }
};

// extra hash
// class Solution {
//    public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int, int> h1;
//         unordered_map<int, int> h2;
//         rep(i, nums1.size()) {
//             if (h1.find(nums1[i]) == h1.end()) {
//                 h1[nums1[i]] = 1;
//             } else {
//                 h1[nums1[i]]++;
//             }
//         }
//         rep(i, nums2.size()) {
//             if (h2.find(nums2[i]) == h2.end()) {
//                 h2[nums2[i]] = 1;
//             } else {
//                 h2[nums2[i]]++;
//             }
//         }
//         vector<int> ans;
//         for (auto i = h1.begin(); i != h1.end(); ++i) {
//             if (h2.find(i->first) != h2.end()) {
//                 while (h1[i->first] > 0 && h2[i->first] > 0) {
//                     ans.push_back(i->first);
//                     h1[i->first]--;
//                     h2[i->first]--;
//                 }
//             }
//         }
//         return ans;
//     }
// };

int main() {
    vector<int> nums1{1, 2, 3, 3, 3, 5, 6, 6, 7};
    vector<int> nums2{1, 2, 3, 5, 6, 6, 7};
    Solution s;
    vector<int> k = s.intersect(nums1, nums2);
    rep(i, k.size()) { cout << k[i] << ","; }
    return 0;
}
