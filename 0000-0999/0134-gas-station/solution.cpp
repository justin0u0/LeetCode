/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/gas-station/
 * Runtime: 144ms
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 * Description:
 *  Maintain prefix sum of the gas - cost array.
 *
 *  Also maintain a sliding window with length N and maintain the minimum
 *  value in the sliding window of the prefix sum array.
 *
 *  Sum is equals to negative sum of (gas - cost) array of which values
 *  are prior to the sliding windows.
 *
 *  If sum + minimum value in the sliding window is greater or equal to 0,
 *  then we get the answer.
 */

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = (int)gas.size();

    vector<int> arr(2 * n);
    arr[0] = gas[0] - cost[0];

    deque<int> candidates;
    candidates.emplace_back(0);

    for (int i = 1; i < n; ++i) {
      arr[i] = arr[i - 1] + gas[i] - cost[i];

      while (!candidates.empty() && arr[candidates.back()] >= arr[i]) {
        candidates.pop_back();
      }
      candidates.emplace_back(i);
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
      arr[n + i] = arr[n + i - 1] + gas[i] - cost[i];

      if (sum + arr[candidates.front()] >= 0) {
        return i;
      }

      sum += cost[i] - gas[i];
      if (candidates.front() == i) {
        candidates.pop_front();
      }
      while (!candidates.empty() && arr[candidates.back()] >= arr[n + i]) {
        candidates.pop_back();
      }
      candidates.emplace_back(n + i);
    }

    return -1;
  }
};
