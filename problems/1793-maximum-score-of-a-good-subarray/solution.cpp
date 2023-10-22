/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-score-of-a-good-subarray/
 * Runtime: 78ms (99.56%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maximumScore(const vector<int>& nums, int k) {
    int i = k;
    int j = k;
    const int n = nums.size();
    int val = nums[k];
    int answer = val;
    while (i != 0 || j != n - 1) {
      if (i == 0 || (j != n - 1 && nums[i - 1] < nums[j + 1])) {
        ++j;
        val = min(val, nums[j]);
      } else {
        --i;
        val = min(val, nums[i]);
      }
      answer = max(answer, val * (j - i + 1));
    }
    return answer;
  }
};
