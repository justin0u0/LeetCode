/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/optimal-partition-of-string/
 * Runtime: 15ms (98.68%)
 */

class Solution {
public:
  int partitionString(const string& s) {
    int answer = 1;
    bitset<26> bst;
    for (const char& c : s) {
      if (bst.test(c - 'a')) {
        ++answer;
        bst.reset();
      }
      bst.set(c - 'a');
    }

    return answer;
  }
};
