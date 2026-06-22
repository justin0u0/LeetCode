/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-number-of-balloons/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxNumberOfBalloons(const string& text) {
    int cnt[128] = {0};
    for (char c : text) {
      ++cnt[c];
    }
    
    return min({cnt['b'], cnt['a'], cnt['l'] / 2, cnt['o'] / 2, cnt['n']});
  }
};
