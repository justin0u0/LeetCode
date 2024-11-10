/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/
 * Runtime: 42ms (83.52%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  array<int, 32> count;

  inline int getOr() const {
    int res = 0;
    int mask = 1;

    for (int i = 0; i < 32; ++i) {
      if (count[i] != 0) {
        res |= mask;
      }
      mask <<= 1;
    }
    return res;
  }

  inline void update(int num, int incr) {
    for (int i = 0; num != 0; ++i) {
      if (num & 1) {
        count[i] += incr;
      }
      num >>= 1;
    }
  }
public:
  int minimumSubarrayLength(vector<int>& nums, int k) {
    fill(count.begin(), count.end(), 0);

    int j = 0;
    int answer = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
      update(nums[i], 1);
      while (j <= i && getOr() >= k) {
        answer = min(answer, i - j + 1);
        update(nums[j], -1);
        ++j;
      }
    }

    if (answer == INT_MAX) {
      return -1;
    }
    return answer;
  }
};
