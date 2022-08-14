/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/word-ladder-ii/
 * Runtime: 36ms
 */

class PathFinder { 
private:
  vector<string>& wordList;
  vector<vector<int>>& neighbors;
  vector<int>& dist;

  vector<vector<string>> answer;
  vector<int> path;

  void dfs(int u) {
    path.emplace_back(u);

    if (dist[u] == 0) {
      vector<string> box;
      transform(path.rbegin(), path.rend(), back_inserter(box),
        [this](int i) { return wordList[i]; });
      answer.emplace_back(box);
    } else {
      for (int v : neighbors[u]) {
        if (dist[v] + 1 == dist[u]) {
          solve(v);
        }
      }
    }

    path.pop_back();
  }

public:
  PathFinder(vector<string>& wordList, vector<vector<int>>& neighbors, vector<int>& dist)
    : wordList(wordList), neighbors(neighbors), dist(dist) {}

  vector<vector<string>>& solve(int e) {
    dfs(e);
    return answer;
  }
};

class Solution {
private:
  int findIndex(const vector<string>& l, const string& target) {
    return find(l.begin(), l.end(), target) - l.begin();
  }

public:
  vector<vector<string>> findLadders(string& beginWord, string& endWord, vector<string>& wordList) {
    int e = findIndex(wordList, endWord);
    if (e == wordList.size()) {
      return vector<vector<string>>();
    }

    int b = findIndex(wordList, beginWord);
    if (b == wordList.size()) {
      wordList.emplace_back(beginWord);
    }

    int n = wordList.size();
    int m = beginWord.size();

    vector<vector<int>> neighbors(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int diff = 0;
        for (int k = 0; k < m; ++k) {
          if (wordList[i][k] != wordList[j][k]) {
            ++diff;
          }
        }
        if (diff == 1) {
          neighbors[i].emplace_back(j);
          neighbors[j].emplace_back(i);
        }
      }
    }

    vector<int> dist(n, -1);
    queue<int> q;
    q.push(b);
    dist[b] = 0;

    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        int u = q.front();
        q.pop();

        for (int v : neighbors[u]) {
          if (dist[v] == -1) {
            q.push(v);
            dist[v] = dist[u] + 1;
          }
        }
      }
    }

    if (dist[e] == -1) {
      return vector<vector<string>>();
    }

    PathFinder pf(wordList, neighbors, dist);
    return pf.solve(e);
  }
};
