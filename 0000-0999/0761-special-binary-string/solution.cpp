/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/special-binary-string/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string makeLargestSpecial(string s) {
    const int n = s.length();

    bool swap = true;
    while (swap) {
      swap = false;
      for (int mid = 1; mid < n; ++mid) {
        int cnt = 0;
        int l = mid - 1;
        bool lok = false;
        for (l = mid - 1; l >= 0; --l) {
          if (s[l] == '0') {
            --cnt;
          } else {
            ++cnt;
          }
          if (cnt > 0) {
            break;
          }
          if (cnt == 0) {
            lok = true;
            break;
          }
        }

        cnt = 0;
        int r = mid + 1;
        bool rok = false;
        for (r = mid; r < n; ++r) {
          if (s[r] == '0') {
            --cnt;
          } else {
            ++cnt;
          }
          if (cnt < 0) {
            break;
          }
          if (cnt == 0) {
            rok = true;
            break;
          }
        }

        if (lok && rok) {
          string ls = s.substr(l, mid - l);
          string rs = s.substr(mid, r - mid + 1);
          if (ls + rs < rs + ls) {
            s.replace(l, r - l + 1, rs + ls);
            swap = true;
          }
        }
      }
    }
    return s;
  }
};
