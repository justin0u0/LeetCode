/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
 * Runtime: 25ms (99.78%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minimumPushes(const string& word) {
    int cnt[26] = {0};
    for (char c : word) {
      ++cnt[c - 'a'];
    }
    sort(cnt, cnt + 26, greater<int>());

    int pushes = 0;
    for (int i = 0; i < 26; ++i) {
      pushes += cnt[i] * ((i >> 3) + 1);
    }
    return pushes;
  }
};
