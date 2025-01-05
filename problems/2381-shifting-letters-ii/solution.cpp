/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shifting-letters-ii/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int sweepline[50001];
public:
  string shiftingLetters(string& s, vector<vector<int>>& shifts) {
    const int n = s.length();
    memset(sweepline, 0, (n + 1) * sizeof(int));
    for (const auto& shift : shifts) {
      if (shift[2] == 0) {
        --sweepline[shift[0]];
        ++sweepline[shift[1] + 1];
      } else {
        ++sweepline[shift[0]];
        --sweepline[shift[1] + 1];
      }
    }

    int shift = 0;
    for (int i = 0; i < n; ++i) {
      shift += sweepline[i];
      unsigned char c = (unsigned char)s[i] + shift % 26;
      if (c < 'a') {
        c += 26;
      } else if (c > 'z') {
        c -= 26;
      }
      s[i] = c;
    }
    return s;
  }
};
