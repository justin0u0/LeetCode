/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxLength(vector<string>& arr, int i = 0, int mask = 0) {
    if (i == arr.size()) {
      return 0;
    }

    const string& s = arr[i];
    int m = 0;
    for (char c : s) {
      int n = (1 << (c - 'a'));
      if (n & m) {
        return maxLength(arr, i + 1, mask);
      }
      m |= n;
    }

    int answer = maxLength(arr, i + 1, mask);
    if ((m & mask) == 0) {
      answer = max(answer, maxLength(arr, i + 1, mask | m) + (int)s.size());
    }
    return answer;
  }
};
