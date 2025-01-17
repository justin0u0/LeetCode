/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/neighboring-bitwise-xor/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool doesValidArrayExist(const vector<int>& derived) {
    int bit = 0;
    for (int i = 0; i < derived.size() - 1; ++i) {
      bit ^= derived[i];
    }
    return bit ^ 0 == derived.back();
  }
};
