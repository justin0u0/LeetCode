/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-distance-in-arrays/
 * Runtime: 179ms (99.53%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxDistance(vector<vector<int>>& arrays) {
    int minValue = +10001;
    int maxValue = -10001;
    int answer = 0;
    for (const auto& arr : arrays) {
      answer = max(answer, max(maxValue - arr[0], arr.back() - minValue));
      minValue = min(minValue, arr[0]);
      maxValue = max(maxValue, arr.back());
    }
    return answer;
  }
};
