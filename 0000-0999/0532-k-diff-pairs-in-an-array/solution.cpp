/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/k-diff-pairs-in-an-array/
 * Runtime: 38ms
 * Time Complexity: O(NlogN)
 */

class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    const int INF = 0x3f3f3f3f;
    sort(nums.begin(), nums.end());

    unordered_set<int> box;

    int prev = -INF;
    int pairs = 0;
    for (const int& num : nums) {
      if (box.find(num - k) != box.end() && num != prev) {
        ++pairs;
        prev = num;
      }

      box.emplace(num);
    }

    return pairs;
  }
};
