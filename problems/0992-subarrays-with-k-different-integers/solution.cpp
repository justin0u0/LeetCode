/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/subarrays-with-k-different-integers/
 * Runtime: 56ms (91.35%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

// Maintains i, x, y, where:
//  i is the current right-side index
//  x is the left-most index s.t. subarray [x,i] has k-1 distinct integers
//  y is the left-most index s.t. subarray [y,i] has k distinct integers
//
// The answer is sum of (x - y) for all i

class Solution {
public:
  int subarraysWithKDistinct(const vector<int>& nums, int k) {
    int answer = 0;
    int x = 0, y = 0;
    int kx = 0, ky = 0;
    unordered_map<int, int> mx, my;

    for (int i = 0; i < nums.size(); ++i) {
      if (++mx[nums[i]] == 1) {
        if (++kx == k) {
          while (--mx[nums[x++]] != 0) {}
          --kx;
        }
      }
      if (++my[nums[i]] == 1) {
        if (++ky == k + 1) {
          while (--my[nums[y++]] != 0) {}
          --ky;
        }
      }
      answer += (x - y);
    }
    return answer;
  }
};
