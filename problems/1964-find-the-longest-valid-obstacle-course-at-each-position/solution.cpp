/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/
 * Runtime: 230ms (99.31%)
 */

const static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
private:
  vector<int> lcs;
  vector<int> answer;
public:
  vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    lcs.resize(1, INT_MIN);
    answer.clear();

    for (const int& o : obstacles) {
      if (o >= lcs.back()) {
        lcs.emplace_back(o);
        answer.emplace_back(lcs.size() - 1);
      } else {
        auto it = upper_bound(lcs.begin(), lcs.end(), o);
        *it = o;
        answer.emplace_back(it - lcs.begin());
      }
    }
    return answer;
  }
};
