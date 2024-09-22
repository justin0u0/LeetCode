/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/bulls-and-cows/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  string getHint(const string& secret, const string& guess) {
    const int n = secret.size();

    int bulls = 0;
    int sc[10] = {0};
    int gc[10] = {0};
    for (int i = 0; i < n; ++i) {
      if (secret[i] == guess[i]) {
        ++bulls;
      } else {
        ++sc[secret[i] - '0'];
        ++gc[guess[i] - '0'];
      }
    }

    int cows = 0;
    for (int i = 0; i < 10; ++i) {
      cows += min(sc[i], gc[i]);
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
  }
};
