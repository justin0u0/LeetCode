/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/gray-code/
 * Runtime: 3ms (84.98%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> grayCode(int n) {
    // To generate N bits gray code, we can prepend 0 to all (N-1) bits gray
    // code sequence, then follow by prepending 1 to all reversed (N-1) bits
    // gray code.
    // 
    // In this way, we make sure that the two codes in the middle have only the
    // first bit differed, and the last code is always a single 1 followed by
    // zeros, which has is differed by 1 with the first integer 0 too.

    if (n == 1) {
      return {0, 1};
    }

    auto g = grayCode(n - 1);
    g.resize(g.size() << 1);
    const int m = g.size();
    for (int i = 0; i < (m >> 1); ++i) {
      g[m - i - 1] = g[i] | (1 << (n - 1));
    }
    return g;
  }
};
