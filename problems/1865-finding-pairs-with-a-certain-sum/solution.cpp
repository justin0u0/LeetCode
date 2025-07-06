/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/finding-pairs-with-a-certain-sum/
 * Runtime: 278ms (39.46%)
 */

class FindSumPairs {
private:
  vector<int>& nums1;
  vector<int>& nums2;
  unordered_map<int, int> freq;
public:
  FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1), nums2(nums2) {
    for (int num : nums2) {
      ++freq[num];
    }
  }

  void add(int index, int val) {
    --freq[nums2[index]];
    nums2[index] += val;
    ++freq[nums2[index]];
  }

  int count(int tot) {
    int res = 0;
    for (int num : nums1) {
      res += freq[tot - num];
    }
    return res;
  }
};
