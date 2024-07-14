/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-atoms/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string countOfAtoms(string& formula) {
    int mul = 1;
    stack<int> muls;
    int digits = 0;
    int base = 1;
    string atom = "";
    map<string, int> atoms;
    for (int i = formula.size() - 1; i >= 0; --i) {
      if (formula[i] >= '0' && formula[i] <= '9') {
        digits += base * (formula[i] - '0');
        base *= 10;
      } else if (formula[i] == ')') {
        if (digits == 0) {
          digits = 1;
        }
        muls.push(digits);
        mul *= digits;
        digits = 0;
        base = 1;
      } else if (formula[i] == '(') {
        mul /= muls.top();
        muls.pop();
      } else if (formula[i] >= 'a' && formula[i] <= 'z') {
        atom += formula[i];
      } else { // formula[i] >= 'A' && formula[i] <= 'Z'
        atom += formula[i];
        reverse(atom.begin(), atom.end());

        if (digits == 0) {
          digits = 1;
        }
        atoms[atom] += mul * digits;
        digits = 0;
        base = 1;
        atom = "";
      }
    }
    
    string res = "";
    for (auto [k, v] : atoms) {
      res += k;
      if (v != 1) {
        res += to_string(v);
      }
    }
    return res;
  }
};
