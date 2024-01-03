/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
 * Runtime: 8ms (79.85%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
#define MAX_VAL 200
public:
  vector<vector<int>> findMatrix(const vector<int>& nums) {
    vector<int> cnt(nums.size() + 1);
    vector<vector<int>> answer;
    for (int num : nums) {
      if (cnt[num] >= answer.size()) {
        answer.emplace_back(vector<int>{});
      }
      answer[cnt[num]++].emplace_back(num);
    }
    return answer;
  }
};
