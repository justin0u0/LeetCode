/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-k-th-smallest-pair-distance/
 * Runtime: 3ms (98.95%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  const static int maxN = 1e6 + 1;
public:
  int smallestDistancePair(vector<int>& nums, int k) {
    const int n = nums.size();
    sort(nums.begin(), nums.end());

    int l = 0;
    int r = maxN;
    while (l < r) {
      int mid = (l + r) >> 1;

      int j = 0;
      int pairs = 0;
      for (int i = 0; i < n; ++i) {
        while (nums[i] - nums[j] > mid) {
          ++j;
        }
        pairs += i - j;
      }

      if (pairs >= k) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return r;
  }
};
