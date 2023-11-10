/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/
 * Runtime: 286ms (99.09%)
 */

class Solution {
public:
  vector<int> restoreArray(vector<vector<int>>& pairs) {
    unordered_map<int, vector<int>> m;
    for (const auto& p : pairs) {
      m[p[0]].emplace_back(p[1]);
      m[p[1]].emplace_back(p[0]);
    }

    int n = pairs.size() + 1;
    vector<int> arr;
    arr.reserve(n);

    for (const auto& it : m) {
      if (it.second.size() == 1) {
        arr.emplace_back(it.first);
        break;
      }
    }

    int pre = INT_MAX;
    while (arr.size() < n) {
      const auto& v = m[arr.back()];
      int nxt = v[0];
      if (nxt == pre) {
        nxt = v[1];
      }
      pre = arr.back();
      arr.emplace_back(nxt);
    }
    return arr;
  }
};
