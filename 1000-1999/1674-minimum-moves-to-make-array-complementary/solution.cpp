/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-moves-to-make-array-complementary/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minMoves(const vector<int>& nums, const int limit) {
    const int n = nums.size();
    const int maxv = limit + limit;
    vector<int> lines(maxv + 2, 0);
    lines[0] = n;

    for (int i = 0; i < n / 2; ++i) {
      const auto l = nums[i];
      const auto r = nums[n - i - 1];

      --lines[l + r - max(l, r) + 1];
      --lines[l + r];
      ++lines[l + r + 1];
      ++lines[l + r + limit - min(l, r) + 1];
    }

    int moves = 0;
    int res = INT_MAX;
    for (int i = 0; i < maxv + 2; ++i) {
      moves += lines[i];
      res = min(res, moves);
    }
    return res;
  }
};
