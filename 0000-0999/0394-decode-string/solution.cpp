/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/decode-string/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  string decodeString(const string& s) {
    stack<pair<int, string>> stk;
    stk.push({0, ""});

    int x = 0;
    string buf;
    for (char c : s) {
      if (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
      } else if (c == '[') {
        stk.push({x, buf});
        x = 0;
        buf = "";
      } else if (c == ']') {
        auto [k, pre] = stk.top();
        stk.pop();

        pre.reserve(pre.size() + buf.size() * k);
        for (int i = 0; i < k; ++i) {
          pre += buf;
        }
        swap(pre, buf);
      } else {
        buf.push_back(c);
      }
    }

    return buf;
  }
};
