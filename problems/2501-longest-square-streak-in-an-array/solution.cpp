/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-square-streak-in-an-array/
 * Runtime: 8ms (97.78%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  const static int N = 1e5 + 1;

  vector<bool> exists = vector<bool>(Solution::N);
public:
  int longestSquareStreak(const vector<int>& nums) {
    fill(exists.begin(), exists.end(), false);

    int ones = 0;
    for (int num : nums) {
      exists[num] = true;
      if (num == 1) {
        ++ones;
      }
    }

    int answer = ones;
    for (int i = 2; i * i < N; ++i) {
      if (!exists[i]) {
        continue;
      }

      int seqs = 0;
      for (long long j = i; j < N; j *= j) {
        if (!exists[j]) {
          break;
        }
        exists[j] = false;
        ++seqs;
      }
      answer = max(answer, seqs);
    }

    if (answer < 2) {
      return -1;
    }
    return answer;
  }
};
