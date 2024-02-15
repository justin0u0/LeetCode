/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/
 * Runtime: 77ms (99.97%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    long long largest = -1;
    long long sum = nums[0] + nums[1];
    for (int i = 2; i < nums.size(); ++i) {
      if (sum > nums[i]) {
        sum += nums[i];
        largest = sum;
      } else {
        sum += nums[i];
      }
    }
    return largest;
  }
};
