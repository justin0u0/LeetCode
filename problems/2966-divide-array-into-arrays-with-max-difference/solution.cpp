/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/
 * Runtime: 99ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<vector<int>> divideArray(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> box;

    for (int i = 0; i < nums.size(); i += 3) {
      if (nums[i + 2] - nums[i] > k) {
        return vector<vector<int>>{};
      }
      box.emplace_back(vector<int>{nums[i], nums[i + 1], nums[i + 2]});
    }

    return box;
  }
};
