/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/string-compression-iii/
 * Runtime: 3ms (99.15%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  string compressedString(string& word) {
    word.push_back('$');

    string res;
    char cur = word[0];
    int count = 0;
    for (char c : word) {
      if (c != cur) {
        while (count > 0) {
          res.push_back('0' + min(count, 9));
          res.push_back(cur);
          count -= 9;
        }
        cur = c;
        count = 1;
      } else {
        ++count;
      }
    }

    return res;
  }
};
