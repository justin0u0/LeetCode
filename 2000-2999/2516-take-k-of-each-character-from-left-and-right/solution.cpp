/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/
 * Runtime: 7ms (85.85%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
#define ok (count['a'] >= k && count['b'] >= k && count['c'] >= k)
public:
  int takeCharacters(const string& s, const int k) {
    const int n = s.length();
    unsigned int count[128] = {0};

    int j = n;
    while (j != 0 && !ok) {
      --j;
      ++count[s[j]];
    }
    if (!ok) {
      return -1;
    }

    int take = n - j;
    for (int i = 0; i < n; ++i) {
      ++count[s[i]];

      while (j != n && ok) {
        take = min(take, i + 1 + n - j);
        --count[s[j]];
        ++j;
      }
      if (ok) {
        take = min(take, i + 1 + n - j);
      }
    }
    return take; 
  }
};
