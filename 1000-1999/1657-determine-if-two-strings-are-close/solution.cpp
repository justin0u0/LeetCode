/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/determine-if-two-strings-are-close/
 * Runtime: 80ms (93.11%)
 */

class Solution {
public:
  bool closeStrings(const string& word1, const string& word2) {
    vector<int> count1(26, 0);
    vector<int> count2(26, 0);
    bitset<26> vis1;
    bitset<26> vis2;
    for (const char& c : word1) {
      int cc = c - 'a';
      ++count1[cc];
      vis1.set(cc);
    }
    for (const char& c : word2) {
      int cc = c - 'a';
      ++count2[cc];
      vis2.set(cc);
    }

    if (vis1 != vis2) {
      return false;
    }

    sort(count1.begin(), count1.end());
    sort(count2.begin(), count2.end());

    return count1 == count2;
  }
};
