/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-absolute-difference/
 * Runtime: 15ms (76.77%)
 */

class Solution {
public:
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int diff = INT_MAX;
    for (int i = 1; i < arr.size(); ++i) {
      diff = min(diff, arr[i] - arr[i - 1]);
    }
    vector<vector<int>> res;
    for (int i = 1; i < arr.size(); ++i) {
      if (arr[i] - arr[i - 1] == diff) {
        res.push_back({arr[i - 1], arr[i]});
      }
    }
    return res;
  }
};
