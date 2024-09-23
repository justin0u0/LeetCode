/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/convert-a-number-to-hexadecimal/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  constexpr static char hex[] = {
    '0', '1', '2', '3',
    '4', '5', '6', '7',
    '8', '9', 'a', 'b',
    'c', 'd', 'e', 'f'
  };
public:
  string toHex(unsigned num) {
    // Note that the original input is `int num`, but we treat it as unsigned
    // for a logical right shift.

    if (num == 0) {
      return "0";
    }

    string s;
    while (num != 0) {
      s.push_back(hex[num & 15]);
      num >>= 4;
    }
    reverse(s.begin(), s.end());
    return s;
  }
};
