/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/
 * Runtime: 2ms (75.90%)
 */

class Solution {
public:
  int minOperations(const vector<int>& nums) {
    const int n = nums.size();

    const int start = ranges::find(nums, 0) - nums.begin();
    bool asc = true;
    bool desc = true;
    for (int i = 1; i < n; ++i) {
      const int val = nums[(start + i) % n];
      if (val != i) {
        asc = false;
      }
      if (val != n - i) {
        desc = false;
      }
      if (!asc && !desc) {
        return -1;
      }
    }

    if (asc) {
      /* e.g.
      [1,2,3,4,0]
      1. rot x 4
      2. rev+rot+rev
      */
      return min(start, n - start + 2);
    }

    if (desc) {
      /*
      [0,4,3,2,1]
      1. rev+rot*4
      2. rot+rev
      */
      return min(start + 2, n - start);
    }
    return -1;
  }
};
