/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/4sum/
 * Runtime: 23ms (78.76%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, const int target) {
    sort(nums.begin(), nums.end());

    auto next = [&](int i) {
      int j = i + 1;
      while (j != nums.size() && nums[i] == nums[j]) {
        ++j;
      }
      return j;
    };

    const int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < n; i = next(i)) {
      for (int j = i + 1; j < n; j = next(j)) {
        int l = n - 1;
        for (int k = j + 1; k < n; k = next(k)) {
          const long long t = 0LL + target - nums[i] - nums[j] - nums[k];
          while (k < l && nums[l] > t) {
            --l;
          }
          if (k == l) {
            break;
          }
          if (t == nums[l]) {
            res.push_back({nums[i], nums[j], nums[k], nums[l]});
          }
        }
      }
    }
    return res;
  }
};
