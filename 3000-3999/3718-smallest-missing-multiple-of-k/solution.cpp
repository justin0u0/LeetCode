/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-missing-multiple-of-k/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int missingMultiple(const vector<int>& nums, const int k) {
    vector<bool> vis(201, false);
    for (int num : nums) {
      vis[num] = true;
    }
    for (int i = k; ; i += k) {
      if (!vis[i]) {
        return i;
      }
    }
    return 0;
  }
};
