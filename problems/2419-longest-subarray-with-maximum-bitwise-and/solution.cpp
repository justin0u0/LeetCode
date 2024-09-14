/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
 * Runtime: 40ms (99.56%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int longestSubarray(const vector<int>& nums) {
    int target = *max_element(nums.begin(), nums.end());
    int answer = 0;
    int k = 0;
    for (int num : nums) {
      if (num == target) {
        answer = max(answer, ++k);
      } else {
        k = 0;
      }
    }
    return answer;
  }
};
