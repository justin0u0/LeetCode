/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * Runtime: 24ms (98.94%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      while (nums[i] > 0 && nums[nums[i] - 1] > 0) {
        const int j = nums[i] - 1;
        nums[i] = nums[j];
        nums[j] = 0;
      }
      if (nums[i] > 0 && nums[nums[i] - 1] == 0) {
        res.emplace_back(nums[i]);
        --nums[nums[i] - 1];
      }
    }
    return res;
  }
};

/*
[4,3,2,7,8,2,3,1]
[7,3,2,0,8,2,3,1]
[3,3,2,0,8,2,0,1]
[2,3,0,0,8,2,0,1]
[3,0,0,0,8,2,0,1]
[3,0,-,0,8,2,0,1]

[3,0,-,0,1,2,0,0]
[0,0,-,0,3,2,0,0]
*/
