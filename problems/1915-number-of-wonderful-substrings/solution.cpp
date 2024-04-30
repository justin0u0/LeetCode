/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-wonderful-substrings/
 * Runtime: 28ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long wonderfulSubstrings(const string& word) {
    // 1. find number of X where X^xors=0 -> X=xors
    //    -> number of substring where all letter appears an even of times
    // 2. find number of X where X^xors=mask -> X=mask^xors
    //    -> mask can be a ~ j
    //    -> number of substring where exactly one letter appears an odd number of times

    int m[1024] = {0};
    m[0] = 1;

    int xors = 0;
    long long answer = 0;
    for (char c : word) {
      xors ^= (1 << (c - 'a'));
      for (int i = 0; i < 10; ++i) {
        answer += m[(1 << i) ^ xors];
      }
      answer += m[xors];
      ++m[xors];
    }
    return answer;
  }
};
