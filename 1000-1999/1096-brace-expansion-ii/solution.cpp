/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/brace-expansion-ii/
 * Runtime: 1ms (98.21%)
 */

class Solution {
private:
  class Parser {
  private:
    const string& expr;
    int i;

    vector<string> parseExpr() {
      vector<string> lhs{""};

      while (i < expr.length() && expr[i] != ',' && expr[i] != '}') {
        if (expr[i] == '{') {
          auto rhs = parseSet();

          vector<string> merged;
          merged.reserve(lhs.size() * rhs.size());
          for (const auto& ls : lhs) {
            for (const auto& rs : rhs) {
              merged.emplace_back(ls + rs);
            }
          }
          swap(lhs, merged);
        } else {
          auto w = parseWord();
          for (auto& s : lhs) {
            s += w;
          }
        }
      }

      return lhs;
    }

    set<string> parseSet() {
      ++i; // {

      set<string> res;

      while (expr[i] != '}') {
        if (expr[i] == ',') {
          ++i;
        } else {
          auto list = parseExpr();
          for (const auto s : list) {
            res.emplace(s);
          }
        }
      }
   
      ++i; // }

      return res;
    }

    string parseWord() {
      string res = "";
      for (; i < expr.length() && expr[i] >= 'a' && expr[i] <= 'z'; ++i) {
        res += expr[i];
      }

      return res;
    }
  public:
    Parser(const string& expr) : expr(expr), i(0) {}

    vector<string> parse() {
      return parseExpr();
    }
  };
public:
  vector<string> braceExpansionII(const string& expression) {
    /*
    Expr := (Word | Set) Expr?
    
    Set := { Expr (, Expr)? }
    
    Word := Ch | Word?
    
    Ch := a | b | c | .. | z
    */

    Parser p(expression);
    auto list = p.parse();
    ranges::sort(list);
    return list;
  }
};
