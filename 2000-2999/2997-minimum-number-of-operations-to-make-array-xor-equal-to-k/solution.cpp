/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/
 * Runtime: 33ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minOperations(vector<int>& nums, int k) {
    int xors = 0;
    for (int num : nums) {
      xors ^= num;
    }
    int answer = 0;
    for (int i = 1; i <= max(k, xors); i <<= 1) {
      if ((xors & i) != (k & i)) {
        ++answer;
      }
    }
    return answer;
  }
};
