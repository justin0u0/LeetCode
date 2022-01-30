/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/rotate-array/
 * Runtime: 24ms
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

class Solution {
private:
  void rotate(int* ptr, int* end, int k) {
    if (k == 0 || end - ptr == 1) {
      return;
    }

    int* lptr = ptr;
    int* rptr = end - k;

    for (int i = 0; i < k; ++i) {
      swap(*lptr, *rptr);
      ++lptr;
      ++rptr;
    }

    rotate(ptr + k, end, k % (end - ptr - k));
  }
public:
  void rotate(vector<int>& nums, int k) {
    int n = (int)nums.size();
    int* arr = nums.data();

    rotate(arr, arr + n, k % n);
  }
};
