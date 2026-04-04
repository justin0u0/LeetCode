/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/decode-the-slanted-ciphertext/
 * Runtime: 25ms (73.73%)
 */

class Solution {
public:
  string decodeCiphertext(const string& encodedText, const int rows) {
    if (encodedText == "") {
      return "";
    }

    const int n = encodedText.length();
    const int cols = n / rows;

    string res = "";
    for (int i = 0; i < cols; ++i) {
      for (int j = 0; j < rows && i + j < cols; ++j) {
        res.push_back(encodedText[j * cols + i + j]);
      }
    }
    while (res.back() == ' ') {
      res.pop_back();
    }
    return res;
  }
};
