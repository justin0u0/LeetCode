/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/
 * Runtime: 115ms (78.76%)
 */

class Solution {
public:
  string findLexSmallestString(const string& s, const int a, const int b) {
    const int n = s.length();

    unordered_set<int> start;
    for (int i = 0; ; i += b) {
      if (!start.emplace(i % n).second) {
        break;
      }
    }

    unordered_set<int> add;
    for (int i = 0; ; i += a) {
      if (!add.emplace(i % 10).second) {
        break;
      }
    }

    string res = s;

    for (int i : start) {
      for (int j1 : add) {
        if (!(b & 1)) {
          string cur;
          for (int k = i; k < i + n; ++k) {
            if ((k - i) & 1) {
              cur.push_back((s[k % n] - '0' + j1) % 10 + '0');
            } else {
              cur.push_back(s[k % n]);
            }
          }
          res = min(res, cur);
          continue;
        }

        for (int j2 : add) {
          string cur;
          for (int k = i; k < i + n; ++k) {
            if ((k - i) & 1) {
              cur.push_back((s[k % n] - '0' + j1) % 10 + '0');
            } else {
              cur.push_back((s[k % n] - '0' + j2) % 10 + '0');
            }
          }
          res = min(res, cur);
        }
      }
    }

    return res;
  }
};
