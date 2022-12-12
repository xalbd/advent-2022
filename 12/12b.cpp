#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#include "../utility.hpp"
using namespace std;

struct loc {
    int r, c;
};

bool operator<(const loc& lhs, const loc& rhs) {
    return lhs.r <= rhs.r && lhs.c <= rhs.c;
}
bool operator==(const loc& lhs, const loc& rhs) {
    return lhs.r == rhs.r && lhs.c == rhs.c;
}

int bfs(int start, int end, int steps, map<int, vector<int> > adj, int r, int c) {
    vector<int> visited;
    visited.resize(r * c, false);
    queue<pair<int, int> > list;
    visited[start] = true;
    list.push(make_pair(start, 0));

    while (!list.empty()) {
        pair<int, int> c = list.front();
        list.pop();
        if (c.first == end) return c.second;

        for (auto next : adj.at(c.first)) {
            if (visited[next]) continue;
            list.push(make_pair(next, c.second + 1));
            visited[next] = true;
        }
    }
    return 10000;
}

void solve(string filename) {
    ifstream file(filename);
    string s;
    vector<string> parsed;
    vector<string> graph;
    loc start, end;
    int starti, endi;

    int r = 0, c;
    while (getline(file, s)) {
        graph.push_back(s);
        for (c = 0; c < s.length(); c++) {
            loc temp;
            if (s[c] == 'S') {
                temp.r = r;
                temp.c = c;
                start = temp;
            }
            else if (s[c] == 'E') {
                temp.r = r;
                temp.c = c;
                end = temp;
            }
        }
        r++;
    }
    c = graph[0].length();
    graph[start.r][start.c] = 'a';
    graph[end.r][end.c] = 'z';
    starti = start.r * c + start.c;
    endi = end.r * c + end.c;

    map<int, vector<int> > adj;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int current = i * c + j;
            vector<int> adjacencies;
            loc temp;
            if (i - 1 >= 0 && graph[i - 1][j] - graph[i][j] <= 1) {
                adjacencies.push_back((i - 1) * c + j);
            }
            if (i + 1 < r && graph[i + 1][j] - graph[i][j] <= 1) {
                adjacencies.push_back((i + 1) * c + j);
            }
            if (j - 1 >= 0 && graph[i][j - 1] - graph[i][j] <= 1) {
                adjacencies.push_back(i * c + (j - 1));
            }
            if (j + 1 < c && graph[i][j + 1] - graph[i][j] <= 1) {
                adjacencies.push_back(i * c + (j + 1));
            }
            adj.insert(make_pair(current, adjacencies));
        }
    }

    int out = bfs(starti, endi, 0, adj, r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (graph[i][j] == 'a') {
                out = min(out, bfs(i * c + j, endi, 0, adj, r, c));
            }
        }
    }
    cout << out << endl;

    file.close();
}

int main() {
    solve("12example.txt");
    solve("12input.txt");
}