/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/continuous-subarrays/
 * Runtime: 59ms (99.70%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long continuousSubarrays(const vector<int>& nums) {
    long long sum = 0;

    int j = 0;
    int mn = nums[0];
    int mx = nums[0];
    deque<int> count{0};
    for (int i = 0; i < nums.size(); ++i) {
      const int num = nums[i];

      while (j < i && max(mx, num) - min(mn, num) > 2) {
        if (nums[j] >= mn && nums[j] <= mx) {
          --count.at(nums[j] - mn);
          while (!count.empty() && count.front() == 0) {
            count.pop_front();
            ++mn;
          }
          while (!count.empty() && count.back() == 0) {
            count.pop_back();
            --mx;
          }
        }

        ++j;
      }

      if (num >= mn && num <= mx) {
        ++count.at(num - mn);
      } else if (num == mn - 1) {
        count.push_front(1);
        --mn;
      } else if (num == mn - 2) {
        count.push_front(0);
        count.push_front(1);
        mn -= 2;
      } else if (num == mx + 1) {
        count.push_back(1);
        ++mx;
      } else if (num == mx + 2) {
        count.push_back(0);
        count.push_back(1);
        mx += 2;
      } else {
        count.push_back(1);
        mn = num;
        mx = num;
      }

      sum += i - j + 1;
    }

    return sum;
  }
};
