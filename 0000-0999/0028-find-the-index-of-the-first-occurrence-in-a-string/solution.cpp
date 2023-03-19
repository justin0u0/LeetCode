/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
 * Runtime: 0ms (100.00%)
 * Time Complexity: O(N + M)
 * Description:
 *  The KMP algorithm.
 *  Ref: https://www.youtube.com/watch?v=af1oqpnH1vA
 */

class Solution {
public:
  int strStr(const string& t, const string& p) {
    // t: target, p: pattern, find first `p` in `t`
    vector<int> failure(p.size(), 0);
    {
      // compute failure function

      int j = 0;
      for (int i = 1; i < p.size(); ++i) {
        // looks for shorter proper border
        while (j != 0 && p[i] != p[j]) {
          j = failure[j - 1];
        }

        // if matches, increase proper border by 1
        if (p[i] == p[j]) {
          ++j;
        }
        failure[i] = j;
      }
    }

    {
      // match

      int j = 0;
      for (int i = 0; i < t.size(); ++i) {
        while (j != 0 && t[i] != p[j]) {
          j = failure[j - 1];
        }
        if (t[i] == p[j]) {
          ++j;
        }
        if (j == p.size()) {
          return i - j + 1;
        }
      }
    }

    return -1;
  }
};
