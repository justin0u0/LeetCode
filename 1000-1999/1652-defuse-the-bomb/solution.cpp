/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/defuse-the-bomb/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> decrypt(vector<int>& code, int k) {
    if (k == 0) {
      for (int& c : code) {
        c = 0;
      }
      return code;
    }

    const int n = code.size();
    vector<int> res(n);

    auto dec = [&](int k) {
      int sum = 0;
      for (int i = 0; i < k; ++i) {
        sum += code[i];
      }
      for (int i = k; i < n + k; ++i) {
        int c = code[i % n];
        res[i % n] = sum;
        sum += c - code[(i - k) % n];
      }
    };

    if (k < 0) {
      dec(-k);
      return res;
    }

    reverse(code.begin(), code.end());
    dec(k);
    reverse(res.begin(), res.end());
    return res;
  }
};
