/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
 * Runtime: 19ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int countCharacters(vector<string>& words, const string& chars) {
    int cnt[128] = {0};
    for (char c : chars) {
      ++cnt[c];
    }

    int answer = 0;
    for (auto& s : words) {
      int used[128] = {0};
      bool ok = true;
      for (char c : s) {
        if (++used[c] > cnt[c]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        answer += s.length();
      }
    }
    return answer;
  }
};
