/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/word-search-ii/
 * Runtime: 76ms (99.27%)
 */

class Solution {
private:
  class Trie {
  public:
    Trie* next[26];
    string* word;
    int count;

    Trie() : next(), word(nullptr), count(0) {}

    static void insert(Trie* root, string& s) {
      ++root->count;

      for (const char& c : s) {
        Trie*& next = root->next[c - 'a'];
        if (next == nullptr) {
          next = new Trie;
        }
        root = next;
        ++root->count;
      }

      root->word = &s;
    }

    static void remove(Trie* root, string& s) {
      --root->count;

      for (const char& c : s) {
        root = root->next[c - 'a'];
        --root->count;
      }

      root->word = nullptr;
    }
  };

  class Solver {
  private:
    const vector<vector<char>>& board;
    int n;
    int m;
    Trie* root;
    vector<string>& answer;
    vector<vector<bool>> vis;

    const int di[4] = {0, 0, 1, -1};
    const int dj[4] = {1, -1, 0, 0};
  public:
    Solver(const vector<vector<char>>& board, int n, int m, Trie* root, vector<string>& answer)
      : board(board), n(n), m(m), root(root), answer(answer), vis(n, vector<bool>(m, false)) {
    }

    void dfs(int i, int j, Trie* t) {
      vis[i][j] = true;

      if (t->word != nullptr) {
        answer.emplace_back(*t->word);
        Trie::remove(root, *t->word);
      }

      for (int k = 0; k < 4; ++k) {
        int newi = i + di[k];
        int newj = j + dj[k];

        if (newi < 0 || newj < 0 || newi >= n || newj >= m || vis[newi][newj]) {
          continue;
        }

        Trie* newt = t->next[board[newi][newj] - 'a'];
        if (newt == nullptr || newt->count == 0) {
          continue;
        }

        dfs(newi, newj, newt);
      }

      vis[i][j] = false;
    }
  };
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie* root = new Trie;
    for (string& word : words) {
      Trie::insert(root, word);
    }

    vector<string> answer;
    int n = board.size();
    int m = board[0].size();
    Solver solver(board, n, m, root, answer);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        Trie* t = root->next[board[i][j] - 'a'];
        if (t != nullptr) {
          solver.dfs(i, j, t);
        }
      }
    }

    return answer;
  }
};
