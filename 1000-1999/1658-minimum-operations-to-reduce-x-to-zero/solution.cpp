/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
 * Runtime: 165ms
 */

class Solution {
public:
  int minOperations(vector<int>& nums, int x) {
    int tot = accumulate(nums.begin(), nums.end(), 0);

    int n = (int)nums.size();
    int minOps = n + 1;
    int i = 0;
    for (int j = 0; j < n; ++j) {
      tot -= nums[j];
      while (tot < x && i <= j) {
        tot += nums[i];
        ++i;
      }

      if (tot == x) {
        minOps = min(minOps, i + n - j - 1);
      }
    }

    if (minOps == n + 1) {
      return -1;
    }

    return minOps;
  }
};
