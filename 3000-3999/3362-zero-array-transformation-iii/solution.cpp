/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/zero-array-transformation-iii/
 * Runtime: 82ms (90.36%)
 */

class Solution {
private:
  int leave[100002];
public:
  int maxRemoval(const vector<int>& nums, vector<vector<int>>& queries) {
    const int n = nums.size();
    const int m = queries.size();

    memset(leave, 0, n * sizeof(int));

    sort(queries.begin(), queries.end(), [](const auto& lhs, const auto& rhs) {
      return lhs[0] < rhs[0];
    });
    priority_queue<int> pq;

    int sum = 0;
    int j = 0;
    int pick = 0;
    for (int i = 0; i < n; ++i) {
      while (j < m && queries[j][0] <= i) {
        pq.push(queries[j][1]);
        ++j;
      }

      sum -= leave[i];

      while (sum < nums[i]) {
        if (pq.empty()) {
          return -1;
        }
        const int r = pq.top();
        if (r < i) {
          return -1;
        }
        pq.pop();

        ++sum;
        ++leave[r + 1];
        ++pick;
      }
    }

    return m - pick;
  }
};
