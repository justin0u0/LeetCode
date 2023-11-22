/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/diagonal-traverse-ii/
 * Runtime: 98ms (99.79%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    queue<pair<int, int>> q;
    q.push({0, 0});

    const int n = nums.size();
    vector<int> answer;
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();

      answer.emplace_back(nums[x][y]);
      if (y == 0 && x + 1 < n) {
        q.push({x + 1, y});
      }
      if (y + 1 < nums[x].size()) {
        q.push({x, y + 1});
      }
    }
    return answer;
  }
};
