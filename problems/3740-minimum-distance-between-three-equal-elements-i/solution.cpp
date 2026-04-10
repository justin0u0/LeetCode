/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  int d1[101];
  int d2[101];
public:
  int minimumDistance(const vector<int>& nums) {
    memset(d1, -1, sizeof(d1));
    memset(d2, -1, sizeof(d2));

    int res = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
      const int num = nums[i];
      if (d1[num] < 0) {
        d1[num] = i;
      } else if (d2[num] < 0) {
        d2[num] = d1[num];
        d1[num] = i;
      } else {
        res = min(res, i - d2[num]);
        d2[num] = d1[num];
        d1[num] = i;
      }
    }

    if (res == INT_MAX) {
      return -1;
    }
    return res << 1;
  }
};
