/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/
 * Runtime: 4ms (85.48%)
 */

class Solution {
private:
  int count[100001];
public:
  int findSmallestInteger(vector<int>& nums, int value) {
    memset(count, 0, value * sizeof(int));
    for (int num : nums) {
      ++count[((num % value) + value) % value];
    }

    for (int i = 0; ; ++i) {
      if ((count[i % value]--) == 0) {
        return i;
      }
    }
    return 0;
  }
};
