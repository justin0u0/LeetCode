/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-gap/
 * Runtime: 168ms (99.13%)
 */

class Solution {
public:
  int maximumGap(vector<int>& nums) {
    if (nums.size() <= 2) {
      return nums.back() - nums.front();
    }

    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    for (const int& num : nums) {
      minVal = min(minVal, num);
      maxVal = max(maxVal, num);
    }

    int n = nums.size();
    int gap = (maxVal - minVal - 1) / (n - 1) + 1;
    vector<int> minBuckets(n - 1, INT_MAX);
    vector<int> maxBuckets(n - 1, INT_MIN);
    for (const int& num : nums) {
      if (num == minVal || num == maxVal) {
        continue;
      }

      int i = (num - minVal) / gap;
      minBuckets[i] = min(minBuckets[i], num);
      maxBuckets[i] = max(maxBuckets[i], num);
    }

    int answer = 0;
    int prev = minVal;
    for (int i = 0; i < n - 1; ++i) {
      if (minBuckets[i] == INT_MAX) {
        continue;
      }

      answer = max(answer, minBuckets[i] - prev);
      prev = maxBuckets[i];
    }

    return max(answer, maxVal - prev);
  }
};
