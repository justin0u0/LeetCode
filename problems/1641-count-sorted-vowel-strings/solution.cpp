/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-sorted-vowel-strings/
 * Runtime: 0ms
 */

class Solution {
public:
  int countVowelStrings(int n) {
    vector<int> sum(5, 1);
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < 5; ++j) {
        sum[j] += sum[j - 1];
      }
    }

    return accumulate(sum.begin(), sum.end(), 0);
  }
};
