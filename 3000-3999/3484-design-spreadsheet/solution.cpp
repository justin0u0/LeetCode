/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/design-spreadsheet/
 * Runtime: 48ms (92.82%)
 */

class Spreadsheet {
private:
  unordered_map<int, int> m[26];

  inline pair<int, int> cellID(const string& cell) {
    int col = cell[0] - 'A';
    int row = 0;
    for (int i = 1; i < cell.size(); ++i) {
      row = row * 10 + cell[i] - '0';
    }
    return {col, row};
  }
public:
  Spreadsheet(int rows) {}
  
  void setCell(const string& cell, int value) {
    auto [col, row] = cellID(cell);
    m[col][row] = value;
  }
  
  void resetCell(const string& cell) {
    auto [col, row] = cellID(cell);
    m[col][row] = 0;
  }
  
  int getValue(const string& formula) {
    int split;
    for (int i = 0; i < formula.size(); ++i) {
      if (formula[i] == '+') {
        split = i;
        break;
      }
    }

    int x, y;

    const string& s1 = formula.substr(1, split - 1);
    if (s1[0] >= '0' && s1[0] <= '9') {
      x = stoi(s1);
    } else {
      auto [col, row] = cellID(s1);
      x = m[col][row];
    }

    const string& s2 = formula.substr(split + 1);
    if (s2[0] >= '0' && s2[0] <= '9') {
      y = stoi(s2);
    } else {
      auto [col, row] = cellID(s2);
      y = m[col][row];
    }

    return x + y;
  }
};
