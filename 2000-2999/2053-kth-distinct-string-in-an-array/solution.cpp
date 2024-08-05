/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/kth-distinct-string-in-an-array/
 * Runtime: 7ms (99.07%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string, int> m;
    for (const auto& s : arr) {
      ++m[s];
    }

    for (const auto& s : arr) {
      if (m.at(s) == 1) {
        --k;
        if (k == 0) {
          return s;
        }
      }
    }

    return "";
  }
};
