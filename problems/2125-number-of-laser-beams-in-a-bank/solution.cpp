/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
 * Runtime: 44ms (99.59%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int numberOfBeams(const vector<string>& bank) {
    int answer = 0;
    int pre = 0;
    for (const auto& s : bank) {
      int cur = count(s.begin(), s.end(), '1');
      if (cur != 0) {
        answer += pre * cur;
        pre = cur;
      }
    }
    return answer;
  }
};
