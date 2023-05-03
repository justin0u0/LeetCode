/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-difference-of-two-arrays/
 * Runtime: 35ms (95.86%)
 */

class Solution {
private:
  const int base = 1000;
public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<bool> exists1(2001, false);
    for (const int& num : nums2) {
      exists1[num + base] = true;
    }
    vector<bool> exists2(2001, false);
    for (const int& num : nums1) {
      exists2[num + base] = true;
    }

    int i = 0;
    for (const int num : nums1) {
      if (!exists1[num + base]) {
        nums1[i++] = num;
        exists1[num + base] = true;
      }
    }
    nums1.resize(i);
    
    i = 0;
    for (const int num : nums2) {
      if (!exists2[num + base]) {
        nums2[i++] = num;
        exists2[num + base] = true;
      }
    }
    nums2.resize(i);

    return vector<vector<int>>{nums1, nums2};
  }
};
