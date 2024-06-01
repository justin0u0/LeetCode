/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/single-number-iii/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    int xorAll = 0;
    for (auto num: nums) xorAll ^= num;

    int key = 1 << __builtin_ctz(xorAll);

    vector<int> singleNumbers(2);
    for (auto num: nums) singleNumbers[!(num & key)] ^= num;
    return singleNumbers;
  }
};
