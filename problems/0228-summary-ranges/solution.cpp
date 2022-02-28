/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/summary-ranges/
 * Runtime: 0ms
 */

class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums) {
    int n = (int)nums.size();
    vector<string> answer;
    if (n == 0) {
      return answer;
    }

    string s = to_string(nums[0]);
    int pre = nums[0];
    nums.emplace_back(nums.back());
    ++n;

    for (int i = 1; i < n; ++i) {
      if (nums[i] - 1 != nums[i - 1]) {
        if (pre != nums[i - 1]) {  
          s += "->" + to_string(nums[i - 1]);
        }

        answer.emplace_back(s);
        s = to_string(nums[i]);
        pre = nums[i];
      }
    }

    return answer;
  }
};
