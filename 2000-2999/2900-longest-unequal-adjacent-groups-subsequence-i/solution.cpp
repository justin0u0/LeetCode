/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
    int j = 1;
    for (int i = 1; i < words.size(); ++i) {
      if (groups[i - 1] != groups[i]) {
        words[j++] = words[i];
      }
    }
    words.resize(j);
    return words;
  }
};
