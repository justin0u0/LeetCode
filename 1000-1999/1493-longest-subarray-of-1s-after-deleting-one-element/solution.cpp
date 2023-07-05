/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
 * Runtime: 32ms (97.95%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int longestSubarray(const vector<int>& nums) {
    int answer = 0;
    int last = 0;
    int count = 0;
    int zeros = 0;

    for (const int num : nums) {
      if (num == 1) {
        ++count;
      } else {
        answer = max(answer, last + count);
        last = count;
        count = 0;
        ++zeros;
      }
    }

    answer = max(answer, last + count);
    if (answer != 0 && !zeros) {
      --answer;
    }
    return answer;
  }
};
