/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int countTriplets(vector<int>& arr) {
    // We know that XOR(arr[a:b]) = XOR(arr[0:a-1])^XOR(arr[0:b]). We want to
    // find all i,j,k where XOR(arr[i:j-1]) = XOR(arr[j:k]). That is,
    // XOR(arr[0:i-1])^XOR(arr[0:j-1]) = XOR(arr[0:j-1])^XOR(arr[0:k]). Which
    // can be simplified as XOR(arr[0:i-1]) = XOR(arr[0:k]).

    arr.insert(arr.begin(), 0);
    for (int i = 1; i < arr.size(); ++i) {
      arr[i] ^= arr[i - 1];
    }
    int answer = 0;
    for (int i = 0; i < arr.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (arr[i] == arr[j]) {
          answer += i - j - 1;
        }
      }
    }
    return answer;
  }
};
