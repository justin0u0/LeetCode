/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/combination-sum-ii/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    int numbers[51] = {0};
    for (int c : candidates) {
      ++numbers[c];
    }

    vector<vector<int>> answer;
    vector<int> box;

    function<void(int, int)> dfs = [&](int x, int t) {
      if (t == 0) {
        answer.emplace_back(box);
        return;
      }
      if (x > t) {
        return;
      }

      if (numbers[x] != 0 && x <= t) {
        box.emplace_back(x);
        --numbers[x];
        dfs(x, t - x);
        ++numbers[x];
        box.pop_back();
      }

      dfs(x + 1, t);
    };

    dfs(1, target);
    return answer;
  }
};
