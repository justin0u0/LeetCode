/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
 * Runtime: 23ms (98.29%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool winnerOfGame(const string& colors) {
    int a = 0;
    int b = 0;
    for (int i = 1; i < colors.size() - 1; ++i) {
      const char c = colors[i];
      if (c == colors[i - 1] && c == colors[i + 1]) {
        if (c == 'A') {
          ++a;
        } else {
          ++b;
        }
      }
    }
    return a > b;
  }
};
