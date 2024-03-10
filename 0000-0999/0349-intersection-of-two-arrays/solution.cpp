/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/intersection-of-two-arrays/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> intersection(const vector<int>& nums1, const vector<int>& nums2) {
    vector<bool> seen(1001, false);
    for (int num : nums1) {
      seen[num] = true;
    }
    vector<int> res;
    for (int num : nums2) {
      if (seen[num]) {
        res.emplace_back(num);
        seen[num] = false;
      }
    }
    return res;
  }
};
