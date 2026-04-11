/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/
 * Runtime: 25ms (98.00%)
 */

class Solution {
private:
  int d1[100001];
  int d2[100001];
public:
  int minimumDistance(const vector<int>& nums) {
    const int n = nums.size();
    memset(d1, -1, (n + 1) * sizeof(int));
    memset(d2, -1, (n + 1) * sizeof(int));

    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
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
