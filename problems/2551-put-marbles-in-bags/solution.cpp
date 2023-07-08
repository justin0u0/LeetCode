/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/put-marbles-in-bags/
 * Runtime: 140ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long putMarbles(const vector<int>& weights, int k) {
    vector<int> box;
    box.reserve(k);
    for (int i = 1; i < weights.size(); ++i) {
      box.emplace_back(weights[i] + weights[i - 1]);
    }
    sort(box.begin(), box.end());

    long long answer = 0;
    auto it = box.cbegin();
    auto rit = box.crbegin();
    for (int i = 1; i < k; ++i) {
      answer += (*it) - (*rit);
      ++it;
      ++rit;
    }
    if (answer < 0) {
      return -answer;
    }
    return answer;
  }
};
