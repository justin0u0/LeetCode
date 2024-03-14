/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/binary-subarrays-with-sum/
 * Runtime: 33ms (59.47%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int numSubarraysWithSum(const vector<int>& nums, int goal) {
    unordered_map<int, int> m;
    int sum = 0;
    m.emplace(0, 1);
    int answer = 0;
    for (int num : nums) {
      sum += num;
      answer += m[sum - goal];
      ++m[sum];
    }
    return answer;
  }
};
