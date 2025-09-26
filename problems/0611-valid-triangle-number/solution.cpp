/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/valid-triangle-number/
 * Runtime: 39ms (30.67%)
 */

class Solution {
public:
  int triangleNumber(vector<int>& nums) {
    const int n = nums.size();
    sort(nums.begin(), nums.end());

    int total = 0;
    for (int i = 0; i < n; ++i) {
      int k = 0;
      for (int j = i + 1; j < n; ++j) {
        k = max(k, j + 1);
        while (k < n && nums[i] + nums[j] > nums[k]) {
          ++k;
        }
        total += k - j - 1;
      }
    }
    return total;
  }
};
