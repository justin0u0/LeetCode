/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-vowel-strings-in-ranges/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  int sum[100001];

  inline bool isVowel(const char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
public:
  vector<int> vowelStrings(const vector<string>& words, const vector<vector<int>>& queries) {
    for (int i = 0; i < words.size(); ++i) {
      if (isVowel(words[i].front()) && isVowel(words[i].back())) {
        sum[i + 1] = sum[i] + 1;
      } else {
        sum[i + 1] = sum[i];
      }
    }

    vector<int> res;
    res.reserve(queries.size());
    for (const auto& q : queries) {
      res.emplace_back(sum[q[1] + 1] - sum[q[0]]);
    }
    return res;
  }
};
