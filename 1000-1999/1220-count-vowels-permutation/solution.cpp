/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-vowels-permutation/
 * Runtime: 9ms
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int countVowelPermutation(int n) {
    int* pre = new int[5]{1, 1, 1, 1, 1};
    int* cur = new int[5];

    while (--n) {
      cur[0] = ((pre[1] + pre[2]) % mod + pre[4]) % mod;  // ea/ia/ua
      cur[1] = (pre[0] + pre[2]) % mod;                   // ae/ie
      cur[2] = (pre[1] + pre[3]) % mod;                   // ei/oi
      cur[3] = pre[2];                                    // io
      cur[4] = (pre[2] + pre[3]) % mod;                   // iu/ou
      swap(pre, cur);
    }

    int answer = 0;
    for (int i = 0; i < 5; ++i) {
      answer = (answer + pre[i]) % mod;
    }
    delete[] pre;
    delete[] cur;
    return answer;
  }
};
