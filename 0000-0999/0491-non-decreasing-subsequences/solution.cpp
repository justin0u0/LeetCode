/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/non-decreasing-subsequences/
 * Runtime: 43ms (92.12%)
 */

class Solution {
private:
  class Solver {
  private:
    const vector<int>& nums;
    vector<int> seq;
  public:
    vector<vector<int>> answer;

    Solver(const vector<int>& nums) : nums(nums) {}

    void solve(int i) {
      if (i == nums.size()) {
        if (seq.size() > 1) {
          answer.emplace_back(seq);
        }
        return;
      }

      if (seq.empty() || seq.back() != nums[i]) {
        solve(i + 1);
      }
      if (seq.empty() || seq.back() <= nums[i]) {
        seq.emplace_back(nums[i]);
        solve(i + 1);
        seq.pop_back();
      }
    }
  };
public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    Solver s(nums);
    s.solve(0);
    return s.answer;
  }
};
