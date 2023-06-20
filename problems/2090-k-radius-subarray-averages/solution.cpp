/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/k-radius-subarray-averages/
 * Runtime: 180ms (99.84%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> getAverages(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> answer(n, -1);
    long long sum = 0;
    int sz = k + k + 1;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      if (i + 1 >= sz) {
        answer[i - k] = sum / sz;
        sum -= nums[i + 1 - sz];
      }
    }
    return answer;
  }
};
