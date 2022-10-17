/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-the-sentence-is-pangram/
 * Runtime: 0ms (100.0%)
 */

class Solution {
public:
  bool checkIfPangram(const string& sentence) {
    bitset<26> b;
    for (const char c : sentence) {
      b.set(c - 'a');
    }
    return b.all();
  }
};
