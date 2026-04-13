/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-distance-to-the-target-element/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int getMinDistance(const vector<int>& nums, const int target, const int start) {
    int dist = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == target) {
        dist = min(dist, abs(i - start));
      }
    }
    return dist;
  }
};
