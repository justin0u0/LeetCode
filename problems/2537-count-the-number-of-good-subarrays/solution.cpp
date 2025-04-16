/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-the-number-of-good-subarrays/
 * Runtime: 66ms (95.97%)
 */

class Solution {
public:
  long long countGood(vector<int>& nums, int k) {
    const int n = nums.size();

    unordered_map<int, int> count;

    long long pairs = 0;
    long long good = 0;

    int j = 0;
    for (int i = 0; i < n; ++i) {
      const int num = nums[i];

      const int x = count[num]++;
      pairs += x;

      while (pairs >= k) {
        const int num = nums[j];
        const int x = --count[num];
        pairs -= x;
        ++j;
      }
      good += j;
    }

    return good;
  }
};
