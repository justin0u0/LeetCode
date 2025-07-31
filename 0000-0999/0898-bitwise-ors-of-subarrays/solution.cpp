/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/bitwise-ors-of-subarrays/
 * Runtime: 1405ms (11.82%)
 */

class Solution {
public:
  int subarrayBitwiseORs(vector<int>& arr) {
    const int n = arr.size();
    unordered_set<int> s;

    int m = 0;
    for (int i = 0; i < n; ++i) {
      if (arr[i] != 0) {
        arr[m++] = arr[i];
      }
    }

    for (int i = 0; i < m; ++i) {
      int o = 0;
      for (int j = i; j < min(i + 32, m); ++j) {
        o |= arr[j];
        s.emplace(o);
      }
    }
    return s.size() + (m != n);
  }
};
