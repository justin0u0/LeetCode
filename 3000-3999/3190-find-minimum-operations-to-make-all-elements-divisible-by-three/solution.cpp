/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minimumOperations(const vector<int>& nums) {
    int ops = 0;
    for (int num : nums) {
      ops += (num % 3 != 0);
    }
    return ops;
  }
};
