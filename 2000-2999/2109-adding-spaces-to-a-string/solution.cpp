/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/adding-spaces-to-a-string/
 * Runtime: 2ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  string addSpaces(const string& s, vector<int>& spaces) {
    string res(s.size() + spaces.size(), '?');
    spaces.emplace_back(INT_MAX);

    int j = 0;
    int k = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (i == spaces[k]) {
        res[j++] = ' ';
        ++k;
      }
      res[j++] = s[i];
    }
    return res;
  }
};
