/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/k-diff-pairs-in-an-array/
 * Runtime: 31ms
 * Time Complexity: O(N)
 */

class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    unordered_set<int> box;
    unordered_set<long long> pairs;

    const long long base = 1LL << 30;

    for (const int& num : nums) {
      if (box.find(num - k) != box.end()) {
        pairs.emplace((num - k) * base + num);
      }
      if (box.find(num + k) != box.end()) {
        pairs.emplace(num * base + (num + k));
      }

      box.emplace(num);
    }

    return (int)pairs.size();
  }
};
