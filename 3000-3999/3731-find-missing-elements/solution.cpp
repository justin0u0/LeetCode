/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-missing-elements/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> findMissingElements(const vector<int>& nums) {
    vector<bool> vis(101, false);

    int lo = 100;
    int hi = 0;
    for (int num : nums) {
      vis[num] = true;
      lo = min(lo, num);
      hi = max(hi, num);
    }

    vector<int> res;
    for (int i = lo; i <= hi; ++i) {
      if (!vis[i]) {
        res.emplace_back(i);
      }
    }
    return res;
  }
};
