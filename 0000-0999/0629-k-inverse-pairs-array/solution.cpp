/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/k-inverse-pairs-array/
 * Runtime: 33ms
 * Time Complexity: O(NK)
 * Space Complexity: O(K)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int kInversePairs(int n, int k) {
    vector<int>* pre = new vector<int>(k + 1, 0);
    vector<int>* cur = new vector<int>(k + 1, 0);
    (*pre)[0] = 1;
    (*cur)[0] = 1;

    for (int i = 1; i <= n; ++i) {
      swap(pre, cur); // cur->dp[i], pre->dp[i-1]
      for (int j = 1; j <= k; ++j) {
        if (j < i) {
          (*cur)[j] = ((*cur)[j - 1] + (*pre)[j]) % mod;
        } else {
          (*cur)[j] = (((*cur)[j - 1] + (*pre)[j]) % mod - (*pre)[j - i] + mod) % mod;
        }
      }
    }

    int answer = (*cur)[k];
    delete pre;
    delete cur;

    return answer;
  }
};
