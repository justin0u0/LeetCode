/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
 * Runtime: 3ms (90.05%)
 */

class Solution {
public:
  int numberOfSubstrings(const string& s) {
    const int n = s.length();

    int j = 0;
    vector<int> count(3, 0);

    int sum = 0;
    for (int i = 0; i < n; ++i) {
      ++count[s[i] - 'a'];
      while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
        sum += n - i;
        --count[s[j++] - 'a'];
      }
    }
    return sum;
  }
};
