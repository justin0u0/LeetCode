/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/
 * Runtime: 9ms (96.19%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int findMaxK(vector<int>& nums) {
    bool exists[2001] = {0};
    for (int num : nums) {
      if (num < 0) {
        exists[-num] = true;
      }
    }

    int answer = -1;
    for (int num : nums) {
      if (num > 0 && exists[num]) {
        answer = max(answer, num);
      }
    }
    return answer;
  }
};
