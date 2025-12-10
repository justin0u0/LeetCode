/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/
 * Runtime: 3ms (43.50%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int countPermutations(const vector<int>& complexity) {
    int smallest = *min_element(complexity.begin() + 1, complexity.end());
    if (smallest <= complexity[0]) {
      return 0;
    }

    long long perm = 1;
    for (int i = 1; i < complexity.size(); ++i) {
      perm = (perm * i) % mod;
    }
    return perm;
  }
};
