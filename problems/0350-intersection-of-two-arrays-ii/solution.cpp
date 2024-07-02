/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/intersection-of-two-arrays-ii/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_multiset<int> s;
    for (int num : nums1) {
      s.emplace(num);
    }
    vector<int> res;
    for (int num : nums2) {
      auto it = s.find(num);
      if (it != s.end()) {
        res.emplace_back(num);
        s.erase(it);
      }
    }
    return res;
  }
};
