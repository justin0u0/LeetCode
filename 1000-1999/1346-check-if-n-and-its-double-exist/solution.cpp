/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-n-and-its-double-exist/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool checkIfExist(vector<int>& arr) {
    unordered_set<int> s;
    for (int num : arr) {
      if (s.find(num << 1) != s.end()) {
        return true;
      }
      if ((num & 1) == 0 && s.find(num >> 1) != s.end()) {
        return true;
      }
      s.emplace(num);
    }
    return false;
  }
};
