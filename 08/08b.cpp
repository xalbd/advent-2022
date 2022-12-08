#include <deque>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#include "../utility.hpp"
using namespace std;

void solve(string filename) {
    ifstream file(filename);
    string s;
    vector<vector<int> > graph;
    while (getline(file, s)) {
        if (s == "") break;
        vector<int> temp;
        for (char a : s) {
            temp.push_back(a - '0');
        }
        graph.push_back(temp);
    }

    int r = graph.size(), c = graph[0].size(), output = 0, score = 1, temp = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            score = 1, temp = 0;
            for (int row = i - 1; row >= 0; row--) {
                temp++;
                if (graph[row][j] >= graph[i][j])
                    break;
            }
            score *= temp;
            temp = 0;
            for (int row = i + 1; row < r; row++) {
                temp++;
                if (graph[row][j] >= graph[i][j])
                    break;
            }
            score *= temp;
            temp = 0;
            for (int col = j - 1; col >= 0; col--) {
                temp++;
                if (graph[i][col] >= graph[i][j])
                    break;
            }
            score *= temp;
            temp = 0;
            for (int col = j + 1; col < c; col++) {
                temp++;
                if (graph[i][col] >= graph[i][j])
                    break;
            }
            score *= temp;
            if (score > output) output = score;
        }
    }
    cout << output << endl;
    file.close();
}

int main() {
    solve("08example.txt");
    solve("08input.txt");
}