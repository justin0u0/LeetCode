/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/baseball-game/
 * Runtime: 4ms
 */

class Solution {
public:
  int calPoints(vector<string>& ops) {
    vector<int> scores;
    scores.reserve(ops.size());

    for (const string& op : ops) {
      switch (op[0]) {
      case '+':
        scores.emplace_back(scores.back() + scores[scores.size() - 2]);
        break;
      case 'D':
        scores.emplace_back(scores.back() * 2);
        break;
      case 'C':
        scores.pop_back();
        break;
      default:
        scores.emplace_back(atoi(op.c_str()));
        break;
      }
    }

    return accumulate(scores.begin(), scores.end(), 0);
  }
};
