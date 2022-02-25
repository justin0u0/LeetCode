/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/compare-version-numbers/
 * Runtime: 0ms
 */

class Solution {
public:
  int compareVersion(string version1, string version2) {
    char* s1 = version1.data();
    char* s2 = version2.data();

    char* p1 = s1;
    char* p2 = s2;
    while ((*p1) != '\0' && (*p2) != '\0') {
      while ((*p1) != '\0' && (*p1) != '.') {
        ++p1;
      }
      while ((*p2) != '\0' && (*p2) != '.') {
        ++p2;
      }

      // remove leading zeros
      while (s1 != p1 - 1 && (*s1) == '0') {
        ++s1;
      }
      while (s2 != p2 - 1 && (*s2) == '0') {
        ++s2;
      }
 
      int n = p1 - s1;
      int m = p2 - s2;
      if (n < m) {
        return -1;
      }
      if (n > m) {
        return 1;
      }

      while (n--) {
        if ((*s1) < (*s2)) {
          return -1;
        }
        if ((*s1) > (*s2)) {
          return 1;
        }

        ++s1;
        ++s2;
      }

      if ((*p1) == '.') {
        ++p1;
      }
      if ((*p2) == '.') {
        ++p2;
      }
      s1 = p1;
      s2 = p2;
    }

    int cmp = -1;
    if ((*p2) == '\0') {
      swap(p1, p2);
      swap(s1, s2);
      cmp = 1;
    }

    while ((*p2) != '\0') {
      while ((*p2) != '\0' && (*p2) != '.') {
        ++p2;
      }
      while (s2 != p2 - 1 && (*s2) == '0') {
        ++s2;
      }

      if (s2 != p2 - 1 || (*s2) != '0') {
        return cmp;
      }

      if ((*p2) == '.') {
        ++p2;
      }
      s2 = p2;
    }

    return 0;
  }
};
