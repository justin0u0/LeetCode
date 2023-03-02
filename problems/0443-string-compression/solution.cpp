/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/string-compression/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int compress(vector<char>& chars) {
    chars.emplace_back('\0');

    int l = 0;
    char pre = chars[0];
    int count = 0;
    for (const char c : chars) {
      if (c != pre) {
        chars[l++] = pre;
        if (count != 1) {
          string s = to_string(count);
          for (const char c2 : s) {
            chars[l++] = c2;
          }
        }

        pre = c;
        count = 1;
      } else {
        ++count;
      }
    }

    chars.resize(l);
    return l;
  }
};
