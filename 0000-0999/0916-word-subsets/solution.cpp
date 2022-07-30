/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/word-subsets/
 * Runtime: 150ms
 */

class Solution {
public:
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<int> requirements(26, 0);
    for (const string& word : words2) {
      int cnt[26] = {0};
      for (const char& c : word) {
        ++cnt[c - 'a'];
      }
      for (int i = 0; i < 26; ++i) {
        requirements[i] = max(requirements[i], cnt[i]);
      }
    }

    vector<string> answer;
    for (const string& word : words1) {
      int cnt[26] = {0};
      for (const char& c : word) {
        ++cnt[c - 'a'];
      }

      bool ok = true;
      for (int i = 0; i < 26; ++i) {
        if (cnt[i] < requirements[i]) {
          ok = false;
        }
      }
      if (ok) {
        answer.emplace_back(word);
      }
    }

    return answer;
  }
};
