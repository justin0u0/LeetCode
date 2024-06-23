/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
 * Runtime: 36ms (99.83%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int longestSubarray(const vector<int>& nums, int limit) {
    deque<int> incr;
    deque<int> decr;
    int longest = 0;
    int j = -1;
    for (int i = 0; i < nums.size(); ++i) {
      while (!incr.empty() && nums[incr.back()] > nums[i]) {
        incr.pop_back();
      }
      while (!decr.empty() && nums[decr.back()] < nums[i]) {
        decr.pop_back();
      }
      incr.push_back(i);
      decr.push_back(i);

      while (nums[i] - nums[incr[0]] > limit) {
        j = max(j, incr.front());
        incr.pop_front();
      }
      while (nums[decr[0]] - nums[i] > limit) {
        j = max(j, decr.front());
        decr.pop_front();
      }
      longest = max(longest, i - j);
    }

    return longest;
  }
};
