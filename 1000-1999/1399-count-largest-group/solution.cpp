/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-largest-group/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int countLargestGroup(int n) {
    int sum = 0;
    int cnt[40] = {0};
    for (int i = 1; i <= n; ++i) {
      if (i % 10000 == 0) {
        sum -= 35;
      } else if (i % 1000 == 0) {
        sum -= 26;
      } else if (i % 100 == 0) {
        sum -= 17;
      } else if (i % 10 == 0) {
        sum -= 8;
      } else {
        ++sum;
      }
      ++cnt[sum];
    }

    return count(cnt, cnt + 40, *max_element(cnt, cnt + 40));
  }
};
