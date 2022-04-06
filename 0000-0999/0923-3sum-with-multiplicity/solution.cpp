/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/3sum-with-multiplicity/
 * Runtime: 10ms
 */

class Solution {
public:
  int threeSumMulti(vector<int>& arr, int target) {
    int count[101] = {0};
    for (const int& val : arr) {
      ++count[val];
    }

    const int mod = 1e9 + 7;
    long long answer = 0;
    for (int i = 0; i <= 100; ++i) {
      if (!count[i]) continue;

      for (int j = i; j <= 100; ++j) {
        int k = target - i - j;
        if (k < j) break;

        if (k > 100 || !count[j] || !count[k]) continue;

        long long x = count[i];
        long long y = count[j];
        long long z = count[k];
        if (i == j && j == k) {
          answer += x * (x - 1) * (x - 2) / 6;
        } else if (i == j) {
          answer += (x * (x - 1) / 2) * z;
        } else if (j == k) {
          answer += x * (z * (z - 1) / 2);
        } else {
          answer += x * y * z;
        }

        answer %= mod;
      }
    }

    return answer;
  }
};
