/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/
 * Runtime: 42ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int numberOfWays(const string& corridor) {
    long long answer = 1;
    bool s = false;
    int last = -1;
    for (int i = 0; i < corridor.size(); ++i) {
      if (corridor[i] == 'S') {
        s ^= true;
        if (!s) {
          last = i;
        } else if (last != -1) {
          answer = answer * (i - last) % mod;
        }
      }
    }

    if (s || last == -1) {
      return 0;
    }
    return answer;
  }
};
