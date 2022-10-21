/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/contains-duplicate-ii/
 * Runtime: 196ms (90.56%)
 */

class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();
    if (k >= n) {
      k = n - 1;
    }

    unordered_set<int> box;
    for (int i = 0; i < k; ++i) {
      if (box.find(nums[i]) != box.end()) {
        return true;
      }
      box.emplace(nums[i]);
    }

    for (int l = 0, r = k; r < n; ++l, ++r) {
      if (box.find(nums[r]) != box.end()) {
        return true;
      }
      box.emplace(nums[r]);
      box.erase(nums[l]);
    }

    return false;
  }
};
