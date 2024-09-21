/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/3sum/
 * Runtime: 51ms (93.75%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  inline int next(const vector<int>& nums, const int i) {
    int j = i + 1;
    while (j != nums.size() && nums[i] == nums[j]) {
      ++j;
    }
    return j;
  }
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    const int n = nums.size();

    vector<vector<int>> res;
    for (int i = 0; i < n; i = next(nums, i)) {
      int k = n - 1;
      for (int j = i + 1; j < n; j = next(nums, j)) {
        int target = 0 - nums[i] - nums[j];
        while (j < k && nums[k] > target) {
          --k;
        }
        if (j == k) {
          break;
        }
        if (nums[k] == target) {
          res.push_back({nums[i], nums[j], nums[k]});
        }
      }
    }
    return res;
  }
};
