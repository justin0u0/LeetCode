/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
 * Runtime: 127ms (99.78%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxSubarrayLength(const vector<int>& nums, const int k) {
    int longest = 0;
    int j = 0;
    unordered_map<int, int> freq;
    for (int i = 0; i < nums.size(); ++i) {
      if (++freq[nums[i]] > k) {
        while (nums[j] != nums[i]) {
          --freq[nums[j++]];
        }
        --freq[nums[j++]];
      }

      longest = max(longest, i - j + 1);
    }
    return longest;
  }
};
