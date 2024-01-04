/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/
 * Runtime: 104ms (95.03%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    nums.emplace_back(INT_MAX);
    int pre = -1;
    int cnt = 0;
    int answer = 0;
    for (int num : nums) {
      if (num != pre) {
        if (cnt == 1) {
          return -1;
        }
        answer += (cnt - 1) / 3 + 1;
        pre = num;
        cnt = 1;
      } else {
        ++cnt;
      }
    }
    return answer - 1;
  }
};
