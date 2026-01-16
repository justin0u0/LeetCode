/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/
 * Runtime: 1869ms (14.56%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
    sort(hFences.begin(), hFences.end());
    hFences.insert(hFences.begin(), 1);
    hFences.emplace_back(m);
    sort(vFences.begin(), vFences.end());
    vFences.insert(vFences.begin(), 1);
    vFences.emplace_back(n);

    unordered_set<int> s;
    for (int i = 0; i < hFences.size(); ++i) {
      for (int j = i + 1; j < hFences.size(); ++j) {
        s.emplace(hFences[j] - hFences[i]);
      }
    }

    int maxl = 0;
    for (int i = 0; i < vFences.size(); ++i) {
      for (int j = i + 1; j < vFences.size(); ++j) {
        const int l = vFences[j] - vFences[i];
        if (s.find(l) != s.end()) {
          maxl = max(maxl, l);
        }
      }
    }
    if (maxl == 0) {
      return -1;
    }
    return (long long)maxl * maxl % mod;
  }
};
