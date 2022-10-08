/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/3sum-closest/
 * Runtime: 237ms (95.51%)
 */

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int dist = 0x3f3f3f3f;
    int answer;
    for (int i = 0; i < n; ++i) {
      int j = i + 1;
      int k = n - 1;

      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (abs(sum - target) < dist) {
          dist = abs(sum - target);
          answer = sum;
        }

        if (answer == target) {
          return answer;
        }

        if (sum < target) {
          ++j;
        } else {
          --k;
        }
      }
    }

    return answer;
  }
};
