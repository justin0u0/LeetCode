/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/contiguous-array/
 * Runtime: 221ms
 */

class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    int n = (int)nums.size();

    int pre = 0;
    unordered_map<int, int> pos;
    pos.emplace(pre, 0);

    int answer = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i]) {
        ++pre;
      } else {
        --pre;
      }

      if (pos.find(pre) != pos.end()) {
        answer = max(answer, i + 1 - pos.at(pre));
      } else {
        pos.emplace(pre, i + 1);
      }
    }

    return answer;
  }
};
