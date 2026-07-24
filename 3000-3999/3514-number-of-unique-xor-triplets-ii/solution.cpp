/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-unique-xor-triplets-ii/
 * Runtime: 732ms (60.67%)
 */

class Solution {
public:
  int uniqueXorTriplets(const vector<int>& nums) {
    const int n = nums.size();
    const int m = (1 << 11);

    vector<bool> vis(m, false);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        vis[nums[i] ^ nums[j]] = true;
      }
    }

    vector<bool> vis2(m, false);
    for (int i = 0; i < m; ++i) {
      if (!vis[i]) {
        continue;
      }
      for (int j = 0; j < n; ++j) {
        vis2[i ^ nums[j]] = true;
      }
    }

    return ranges::count(vis2, true);
  }
};
