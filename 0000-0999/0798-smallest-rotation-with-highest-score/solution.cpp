/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-rotation-with-highest-score/
 * Runtime: 51ms (81.17%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  // leave[i] is number of score disappear after i+1 rotation.
  int leave[200001];
public:
  int bestRotation(const vector<int>& nums) {
    const int n = nums.size();
    memset(leave, 0, sizeof(leave));

    // Calculate the score of zero rotation.
    int score = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] <= i) {
        ++score;
        // For each rotation, the index at nums[i] increase by 1. Which means
        // that after i - nums[i] + 1 rotation, the score does not contribute
        // any more.
        ++leave[i - nums[i]];
      }
    }

    int best = score;
    int bestK = 0;
    for (int i = 0; i < n - 1; ++i) {
      // Remove the score after i+1 rotation.
      score -= leave[i];

      // Check if the last number after rotation contribute the score.
      if (nums[i] <= n - 1) {
        ++score;
        // For each rotation, the index at nums[i] increase by 1. Which means
        // after (n - 1) - nums[i] + 1 rotation, the score does not contribute
        // any more.
        ++leave[i + n - nums[i]];
      }
      if (score > best) {
        best = score;
        bestK = i + 1;
      }
    }
    return bestK;
  }
};
