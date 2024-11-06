/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-if-array-can-be-sorted/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool canSortArray(vector<int>& nums) {
    nums.emplace_back(0xFFF);

    int mx = 0;
    int next = 0;
    int bits = 0;
    for (int num : nums) {
      const int b = __builtin_popcount(num);
      if (b != bits) {
        mx = next;
        next = num;
        bits = b;
      } else {
        next = max(next, num);
      }

      if (num < mx) {
        return false;
      }
    }
    return true;
  }
};
