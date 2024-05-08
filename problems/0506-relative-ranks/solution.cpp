/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/relative-ranks/
 * Runtime: 4ms (89.65%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  const string medals[3] = {
    "Gold Medal",
    "Silver Medal",
    "Bronze Medal"
  };
public:
  vector<string> findRelativeRanks(const vector<int>& score) {
    vector<int> arr(score.begin(), score.end());
    sort(arr.begin(), arr.end());
    vector<string> answer;
    answer.reserve(score.size());
    for (int s : score) {
      int rank = arr.end() - lower_bound(arr.begin(), arr.end(), s) - 1;
      if (rank < 3) {
        answer.emplace_back(medals[rank]);
      } else {
        answer.emplace_back(to_string(rank + 1));
      }
    }
    return answer;
  }
};
