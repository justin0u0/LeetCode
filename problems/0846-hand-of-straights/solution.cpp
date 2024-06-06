/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/hand-of-straights/
 * Runtime: 84ms (10.30%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) {
      return false;
    }
    if (groupSize == 1) {
      return true;
    }
    int numGroups = hand.size() / groupSize;
    sort(hand.begin(), hand.end());

    unordered_map<int, queue<int>> groups;
    for (int val : hand) {
      auto it = groups.find(val - 1);
      if (it != groups.end() && !it->second.empty()) {
        int size = it->second.front();
        it->second.pop();
        if (size + 1 != groupSize) {
          groups[val].push(size + 1);
        } else if (--numGroups < 0) {
          return false;
        }
      } else {
        groups[val].push(1);
      }
    }

    return numGroups == 0;
  }
};
