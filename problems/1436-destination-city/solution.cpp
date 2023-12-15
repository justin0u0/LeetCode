/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/destination-city/
 * Runtime: 7ms (85.29%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  string destCity(const vector<vector<string>>& paths) {
    unordered_set<string> src;
    for (auto& path : paths) {
      src.emplace(path[0]);
    }
    for (auto& path : paths) {
      if (src.find(path[1]) == src.end()) {
        return path[1];
      }
    }
    return "";
  }
};
