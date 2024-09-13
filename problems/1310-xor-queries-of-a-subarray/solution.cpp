/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/xor-queries-of-a-subarray/
 * Runtime: 33ms (98.74%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    for (int i = 1; i < arr.size(); ++i) {
      arr[i] ^= arr[i - 1];
    }

    vector<int> answer;
    answer.reserve(queries.size());
    for (const auto& q : queries) {
      if (q[0] == 0) {
        answer.emplace_back(arr[q[1]]);
      } else {
        answer.emplace_back(arr[q[0] - 1] ^ arr[q[1]]);
      }
    }
    return answer;
  }
};
