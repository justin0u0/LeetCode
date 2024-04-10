/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reveal-cards-in-increasing-order/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    const int n = deck.size();
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      q.push(i);
    }

    sort(deck.begin(), deck.end());
    vector<int> answer(n);
    for (int i = 0; i < n; ++i) {
      answer[q.front()] = deck[i];
      q.pop();
      q.push(q.front());
      q.pop();
    }

    return answer;
  }
};
