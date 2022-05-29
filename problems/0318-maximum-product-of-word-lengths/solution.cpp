/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-product-of-word-lengths/
 * Runtime: 41ms
 */

class Solution {
public:
  int maxProduct(vector<string>& words) {
    vector<int> hashes(words.size());

    int n = (int)words.size();
    int answer = 0;
    for (int i = 0; i < n; ++i) {
      string& word = words[i];
      int& hash = hashes[i];
      for (const char& c : word) {
        hash |= 1 << (c - 'a');
      }

      for (int j = 0; j < i; ++j) {
        if ((hash & hashes[j]) == 0) {
          answer = max(answer, (int)word.length() * (int)words[j].length());
        }
      }
    }

    return answer;
  }
};
