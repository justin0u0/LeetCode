/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-happy-string/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  string longestDiverseString(int a, int b, int c) {
    string s = "";

    auto add = [&](int x, int y, int z) {
      if (!x && !y && !z) {
        return false;
      }
      if (x >= y && x >= z) {
        s.push_back('a');
        --a;
      } else if (y >= x && y >= z) {
        s.push_back('b');
        --b;
      } else if (z >= y && z >= x) {
        s.push_back('c');
        --c;
      }
      return true;
    };

    for (int i = 0; ; ++i) {
      if (i >= 2 && s[i - 1] == s[i - 2]) {
        if ((s[i - 1] == 'a' && !add(0, b, c))
          || (s[i - 1] == 'b' && !add(a, 0, c))
          || (s[i - 1] == 'c' && !add(a, b, 0))) {
          return s;
        }
        ++i;
      }

      if (!add(a, b, c)) {
        return s;
      }
    }

    return s;
  }
};
