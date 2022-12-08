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

    int r = graph.size(), c = graph[0].size(), output = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i == 0 || j == 0 || i == r - 1 || j == c - 1) {
                output++;
                continue;
            }
            bool visible = true;
            for (int row = 0; row < i; row++) {
                if (graph[row][j] >= graph[i][j]) visible = false;
            }
            if (visible) {
                output++;
                continue;
            }
            visible = true;
            for (int row = i + 1; row < r; row++) {
                if (graph[row][j] >= graph[i][j]) visible = false;
            }
            if (visible) {
                output++;
                continue;
            }
            visible = true;
            for (int col = 0; col < j; col++) {
                if (graph[i][col] >= graph[i][j]) visible = false;
            }
            if (visible) {
                output++;
                continue;
            }
            visible = true;
            for (int col = j + 1; col < c; col++) {
                if (graph[i][col] >= graph[i][j]) visible = false;
            }
            if (visible) {
                output++;
                continue;
            }
        }
    }
    cout << output << endl;
    file.close();
}

int main() {
    solve("08example.txt");
    solve("08input.txt");
}