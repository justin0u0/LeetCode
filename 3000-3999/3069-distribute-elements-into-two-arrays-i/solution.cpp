/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/distribute-elements-into-two-arrays-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> resultArray(const vector<int>& nums) {
    vector<int> arr1{nums[0]};
    vector<int> arr2{nums[1]};

    for (int i = 2; i < nums.size(); ++i) {
      if (arr1.back() > arr2.back()) {
        arr1.emplace_back(nums[i]);
      } else {
        arr2.emplace_back(nums[i]);
      }
    }
    
    ranges::copy(arr2, back_inserter(arr1));
    return arr1;
  }
};
