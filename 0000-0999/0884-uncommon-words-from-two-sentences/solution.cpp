/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/uncommon-words-from-two-sentences/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<string> uncommonFromSentences(const string& s1, const string& s2) {
    unordered_set<string> uncommon;
    unordered_set<string> seen;
    stringstream ss1(s1);
    string s;
    while (ss1 >> s) {
      if (seen.find(s) != seen.end()) {
        uncommon.erase(s);
      } else {
        uncommon.emplace(s);
      }
      seen.emplace(s);
    }

    stringstream ss2(s2);
    while (ss2 >> s) {
      if (seen.find(s) != seen.end()) {
        uncommon.erase(s);
      } else {
        uncommon.emplace(s);
      }
      seen.emplace(s);
    }

    return vector<string>(uncommon.begin(), uncommon.end());
  }
};
