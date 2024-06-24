/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
 * Runtime: 71ms (98.16%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minKBitFlips(vector<int>& nums, int k) {
    const int n = nums.size();
    const int m = n - k + 1;
    int flips = 0;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (!q.empty() && i - q.front() >= k) {
        q.pop();
      }
      if ((nums[i] ^ (q.size() & 1)) == 0) {
        if (i >= m) {
          return -1;
        }
        ++flips;
        q.push(i);
      }
    }
    return flips;
  }
};
