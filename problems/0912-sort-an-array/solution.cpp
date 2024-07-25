/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sort-an-array/
 * Runtime: 80ms (92.92%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  void heapify(vector<int>& nums, int n, int root) {
    while (true) {
      int child = (root << 1) + 1;
      if (child >= n) {
        break;
      }
      if (child + 1 < n && nums[child + 1] > nums[child]) {
        ++child;
      }
      if (nums[root] < nums[child]) {
        swap(nums[root], nums[child]);
        root = child;
      } else {
        break;
      }
    }
  }
public:
  vector<int> sortArray(vector<int>& nums) {
    const int n = nums.size();
    // Heapsort
    for (int i = n / 2 - 1; i >= 0; --i) {
      heapify(nums, n, i);
    }
    for (int i = n - 1; i >= 0; --i) {
      swap(nums[0], nums[i]);
      heapify(nums, i, 0);
    }
    return nums;
  }
};
