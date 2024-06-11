/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/relative-sort-array/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  int order[1001];
public:
  vector<int> relativeSortArray(vector<int>& arr1, const vector<int>& arr2) {
    memset(order, 0x3f3f3f3f, sizeof(order));
    for (int i = 0; i < arr2.size(); ++i) {
      order[arr2[i]] = i;
    }
    sort(arr1.begin(), arr1.end(), [&](int a, int b) {
      return (order[a] < order[b]) || (order[a] == order[b] && a < b);
    });
    return arr1;
  }
};
