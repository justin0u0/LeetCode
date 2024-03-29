/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
 * Runtime: 61ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long countSubarrays(const vector<int>& nums, int k) {
    const int target = *max_element(nums.begin(), nums.end());
    const int n = nums.size();
    long long answer = 1LL * n * (n + 1) / 2;
    int j = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == target) {
        --k;
      }
      if (k == 0) {
        while (nums[j] != nums[i]) {
          ++j;
        }
        ++j;
        k = 1;
      }
      answer -= (i - j + 1);
    }
    return answer;
  }
};
