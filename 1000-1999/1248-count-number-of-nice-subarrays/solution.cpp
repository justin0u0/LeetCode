/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-number-of-nice-subarrays/
 * Runtime: 53ms (99.01%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int solve(const vector<int>& nums, int k) {
    int j = 0;
    unsigned int answer = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] & 1) {
        --k;
      }
      if (k < 0) {
        while (!(nums[j] & 1)) {
          ++j;
        }
        ++j;
        ++k;
      }
      answer += i - j + 1;
    }
    return answer;
  }
public:
  int numberOfSubarrays(const vector<int>& nums, int k) {
    // exactly k = (at most k) - (at most k - 1)
    return solve(nums, k) - solve(nums, k - 1);
  }
};
