/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/crawler-log-folder/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minOperations(vector<string>& logs) {
    int d = 0;
    for (const auto& l : logs) {
      if (l[0] == '.' && l[1] == '.' && d != 0) {
        --d;
      } else if (l[0] != '.') {
        ++d;
      }
    }
    return d;
  }
};
