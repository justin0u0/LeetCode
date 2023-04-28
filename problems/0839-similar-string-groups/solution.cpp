/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/similar-string-groups/
 * Runtime: 19ms (96.83%)
 */

class Solution {
private:
  int pa[301];

  int find(int x) {
    if (pa[x] == x) {
      return x;
    }
    return (pa[x] = find(pa[x]));
  }

  inline bool check(const string& s1, const string& s2, int m) {
    int d1 = -1;
    int d2 = -1;
    for (int i = 0; i < m; ++i) {
      if (s1[i] != s2[i]) {
        if (d1 == -1) {
          d1 = i;
        } else if (d2 == -1) {
          d2 = i;
        } else {
          return false;
        }
      }
    }

    if (d1 == -1 && d2 == -1) {
      return true;
    }

    return d1 != -1 && d2 != -1 && s1[d1] == s2[d2] && s1[d2] == s2[d1];
  }
public:
  int numSimilarGroups(vector<string>& strs) {
    int n = strs.size();
    for (int i = 0; i < n; ++i) {
      pa[i] = i;
    }

    int m = strs[0].size();
    int groups = n;
    for (int i = 0; i < n; ++i) {
      const string& s1 = strs[i];
      for (int j = i + 1; j < n; ++j) {
        if (check(s1, strs[j], m)) {
          int fx = find(pa[i]);
          int fy = find(pa[j]);
          if (fx != fy) {
            pa[fx] = fy;
            --groups;
          }
        }
      }
    }

    return groups;
  }
};
