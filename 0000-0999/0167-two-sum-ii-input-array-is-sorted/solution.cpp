/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 * Runtime: 8ms
 */

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0;
    int j = (int)numbers.size() - 1;

    while (numbers[i] + numbers[j] != target) {
      if (numbers[i] + numbers[j] < target) {
        ++i;
      } else {
        --j;
      }
    }

    return vector<int>{i + 1, j + 1};
  }
};
