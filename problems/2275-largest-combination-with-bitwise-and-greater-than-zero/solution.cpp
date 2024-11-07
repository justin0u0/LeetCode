/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/
 * Runtime: 5ms (99.25%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int largestCombination(const vector<int>& candidates) {
    int bitcount[24] = {0};
    for (int num : candidates) {
      for (int i = 0; num != 0; ++i) {
        bitcount[i] += (num & 1);
        num >>= 1;
      }
    }

    return *max_element(bitcount, bitcount + 24);
  }
};
