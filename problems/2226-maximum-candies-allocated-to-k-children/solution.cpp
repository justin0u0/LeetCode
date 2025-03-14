/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
 * Runtime: 18ms (85.94%)
 */

class Solution {
public:
  int maximumCandies(const vector<int>& candies, const long long k) {
    int l = 1;
    int r = *max_element(candies.begin(), candies.end()) + 1;
    while (l < r) {
      const int mid = (l + r) >> 1;

      long long sum = 0;
      for (const int c : candies) {
        sum += c / mid;
      }
      if (sum >= k) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l - 1;
  }
};
