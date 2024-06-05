/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-common-characters/
 * Runtime: 3ms (96.29%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<string> commonChars(const vector<string>& words) {
    int common[128];
    memset(common, 0x3f3f3f3f, sizeof(common));
    int cnt[128];
    for (const auto& word : words) {
      memset(cnt, 0, sizeof(cnt));
      for (char c : word) {
        ++cnt[c];
      }
      for (char c = 'a'; c <= 'z'; ++c) {
        common[c] = min(common[c], cnt[c]);
      }
    }

    vector<string> res;
    for (char c = 'a'; c <= 'z'; ++c) {
      while (common[c]--) {
        res.emplace_back(string(1, c));
      }
    }
    return res;
  }
};
