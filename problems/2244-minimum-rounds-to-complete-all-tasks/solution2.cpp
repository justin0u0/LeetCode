/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
 * Runtime: 339ms (55.48%)
 * Time Complexity: O(N)
 */

class Solution {
public:
  int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> box;
    for (const int& task : tasks) {
      ++box[task];
    }

    int answer = 0;
    for (const auto& [k, v] : box) {
      if (v == 1) {
        return -1;
      }

      int c = v / 3;
      if (v % 3 == 0) {
        answer += c;
      } else {
        answer += c + 1;
      }
    }

    return answer;
  }
};
