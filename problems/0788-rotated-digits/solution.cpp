/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/rotated-digits/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  constexpr static int N = 10001;
  constexpr static array<uint8_t, 10> os{0, 0, 1, 0, 0, 1, 1, 0, 0, 1};
  constexpr static array<uint8_t, 10> vs{1, 1, 1, 0, 0, 1, 1, 0, 1, 1};

  constexpr static array<int, N> sum = []{
    array<int, N> arr{0};
    for (int i = 1; i < N; ++i) {
      bool ok = false;
      bool valid = true;
      for (int x = i; x > 0; x /= 10) {
        ok |= os[x % 10];
        valid &= vs[x % 10];
      }
      arr[i] = arr[i - 1] + (valid && ok);
    }
    return arr;
  }();
public:
  int rotatedDigits(const int n) {
    return sum[n];
  }
};
