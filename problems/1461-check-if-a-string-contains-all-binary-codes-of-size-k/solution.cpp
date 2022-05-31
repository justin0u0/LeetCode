/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
 * Runtime: 67ms
 */

class Solution {
public:
  bool hasAllCodes(string s, int k) {
    if ((int)s.length() < k) {
      return false;
    }

    int cur = 0;
    for (int i = 0; i < k; ++i) {
      cur = cur << 1 | (s[i] - '0');
    }

    vector<bool> vis(1 << k, false);
    vis[cur] = true;
    int left = (1 << k) - 1;

    int n = (int)s.length();
    const int mask = ~(1 << k);
    for (int i = k; i < n; ++i) {
      cur = ((cur << 1) | (s[i] - '0')) & mask;
      if (vis[cur] == false) {
        vis[cur] = true;
        --left;
      }
    }

    return left == 0;
  }
};
