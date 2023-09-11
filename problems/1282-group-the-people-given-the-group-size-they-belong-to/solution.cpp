/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
 * Runtime: 3ms (98.93%)
 */

class Solution {
public:
  vector<vector<int>> groupThePeople(const vector<int>& groupSizes) {
    vector<vector<int>> boxes(501);
    vector<vector<int>> answer;
    for (int i = 0; i < groupSizes.size(); ++i) {
      int g = groupSizes[i];
      auto& box = boxes[g];
      box.emplace_back(i);
      if (box.size() == g) {
        answer.emplace_back(box);
        box.clear();
      }
    }
    return answer;
  }
};
