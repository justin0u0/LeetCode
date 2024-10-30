/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minimumMountainRemovals(vector<int>& nums) {
    vector<int> incr{0};
    vector<int> lis;
    lis.reserve(nums.size());
    for (int num : nums) {
      if (num > incr.back()) {
        incr.emplace_back(num);
      } else {
        *lower_bound(incr.begin(), incr.end(), num) = num;
      }
      lis.emplace_back(incr.size() - 1);
    }

    int answer = 0;
    incr.resize(1);
    for (int i = nums.size() - 1; i >= 0; --i) {
      const int num = nums[i];
      if (num > incr.back()) {
        incr.emplace_back(num);
      } else {
        *lower_bound(incr.begin(), incr.end(), num) = num;
      }

      const int llis = lis[i];
      const int rlis = incr.size() - 1;
      if (llis != 1 && rlis != 1) {
        answer = max(answer, llis + rlis - 1);
      }
    }
    return nums.size() - answer;
  }
};
