/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/frequency-of-the-most-frequent-element/
 * Runtime: 120ms (98.30%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    long long incr = 0;
    int j = 0;
    int answer = 1;
    for (int i = 1; i < nums.size(); ++i) {
      incr += 1LL * (nums[i] - nums[i - 1]) * (i - j);
      while (incr > k) {
        incr -= nums[i] - nums[j];
        ++j;
      }
      answer = max(answer, i - j + 1);
    }
    return answer;
  }
};
