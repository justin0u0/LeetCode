/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/four-divisors/
 * Runtime: 22ms (61.82%)
 */

class Solution {
public:
  int sumFourDivisors(const vector<int>& nums) {
    int sum = 0;
    for (const int num : nums) {
      int s = 0;
      int count = 0;
      for (int i = 1; i * i <= num; ++i) {
        if (num % i == 0) {
          if (i * i == num) {
            s += i;
            ++count;
          } else {
            s += i + num / i;
            count += 2;
          }
        }
      }
      if (count == 4) {
        sum += s;
      }
    }
    return sum;
  }
};
