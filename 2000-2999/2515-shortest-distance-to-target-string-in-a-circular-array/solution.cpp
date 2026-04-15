/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int closestTarget(const vector<string>& words, const string target, const int startIndex) {
    const int n = words.size();

    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
      if (words[i] == target) {
        res = min(res, min(abs(i - startIndex), min(startIndex + n - i, i + n - startIndex)));
      }
    }

    if (res == INT_MAX) {
      return -1;
    }
    return res;
  }
};
