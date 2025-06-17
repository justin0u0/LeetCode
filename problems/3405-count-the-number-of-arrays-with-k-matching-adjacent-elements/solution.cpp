/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  constexpr static int N = 100001;
  constexpr static int P = 1e9 + 7;

  constexpr static array<int, N> fact = []{
    array<int, N> res{1};
    for (int i = 1; i < N; ++i) {
      res[i] = (long long)res[i - 1] * i % P;
    }
    return res;
  }();
  
  int pow(long long a, int p) {
    long long res = 1;
    while (p != 0) {
      if (p & 1) {
        res = res * a % P;
      }
      a = a * a % P;
      p >>= 1;
    }
    return res;
  }
  
  int C(int a, int b) {
    return ((long long)fact[a] * pow(fact[b], P - 2) % P) * pow(fact[a - b], P - 2) % P;
  }
public:
  int countGoodArrays(int n, int m, int k) {
    // Assuming that we are inserting x walls within n elements, and each
    // group should be fill in the same number.
    //
    // We can find that inserting x wall within n elements always generate
    // (n - x - 1) indices satisfying arr[i] == arr[i - 1].
    //
    // As we want exactly k = (n - x - 1) indices, therefore x = (n - k - 1).
    //
    // There are C(n - 1, x) combination of putting x walls, and adjacent
    // group should not be fill in the same number. So the total number of
    // combinations are C(n - 1, x) * m * (m - 1) ^ x, which equals to
    // C(n - 1, n - k - 1) * m * (m - 1)^(n - k - 1).

    // n = 5
    // x = 1 => o | o o o o       => k=3
    // x = 2 => o | o | o o o     => k=2
    // x = 3 => o | o | o | o o   => k=1
    // x = 4 => o | o | o | o | o => k=0

    return ((long long)C(n - 1, n - k - 1) * m % P) * pow(m - 1, n - k - 1) % P;
  }
};
