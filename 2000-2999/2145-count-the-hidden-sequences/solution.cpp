/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-the-hidden-sequences/
 * Runtime: 2ms (41.13%)
 */

class Solution {
private:
  const int cap = 200001;
public:
  int numberOfArrays(vector<int>& differences, int lower, int upper) {
    int sum = 0;
    int lo = INT_MAX;
    int up = INT_MIN;
    for (const int d : differences) {
      sum += d;
      sum = min(sum, cap);
      sum = max(sum, -cap);
      lo = min(lo, sum);
      up = max(up, sum);
    }

    if (lo < 0) {
      lower -= lo;
    }
    if (up > 0) {
      upper -= up;
    }
    return max(0, upper - lower + 1);
  }
};
