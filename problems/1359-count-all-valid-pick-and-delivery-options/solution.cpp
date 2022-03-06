/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
 * Runtime: 2ms
 */

class Solution {
public:
  int countOrders(int n) {
    const int mod = 1e9 + 7;
    long long answer = 1;
    for (int i = 1; i <= n; ++i) {
      answer = (answer * i * (2 * i - 1)) % mod;
    }

    return answer;
  }
};
