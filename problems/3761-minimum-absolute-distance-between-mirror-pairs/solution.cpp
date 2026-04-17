/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/
 * Runtime: 112ms (65.44%)
 */

class Solution {
public:
  int minMirrorPairDistance(const vector<int>& nums) {
    int dist = INT_MAX;

    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
      int num = nums[i];
      if (m.find(num) != m.end()) {
        dist = min(dist, i - m[num]);
      }
      int rev = 0;
      while (num != 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
      }
      m[rev] = i;
    }

    if (dist == INT_MAX) {
      return -1;
    }
    return dist;
  }
};
