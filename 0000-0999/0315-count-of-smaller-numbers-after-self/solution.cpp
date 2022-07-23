/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-of-smaller-numbers-after-self/
 * Runtime: 170ms
 */

class BIT {
private:
  int size;
  int* arr;
public:
  BIT(int size) : size(size) {
    arr = new int[size]();
  }

  ~BIT() {
    delete[] arr;
  }

  void add(int x, int val) {
    for (int i = x; i < size; i += (i & -i)) {
      arr[i] += val;
    }
  }

  int sum(int x) {
    int s = 0;
    for (int i = x; i > 0; i -= (i & -i)) {
      s += arr[i];
    }
    return s;
  }
};

class Solution {
private:
  const int base = 10001;
public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> answer(nums.size());
    BIT bit(base * 2);
    for (int i = nums.size() - 1; i >= 0; --i) {
      nums[i] += base;
      answer[i] = bit.sum(nums[i] - 1);
      bit.add(nums[i], 1);
    }

    return answer;
  }
};
