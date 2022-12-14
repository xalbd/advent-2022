#include <deque>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include "../utility.hpp"
using namespace std;

int move(vector<pair<int, int> > &s, pair<int, int> &cur, int low) {
    bool possible = true;
    // Straight down
    for (auto a : s) {
        if (a.first == cur.first && a.second == cur.second + 1) possible = false;
    }
    if (possible) {
        cur.second++;
        return 1;
    }

    // Down and left
    possible = true;
    for (auto a : s) {
        if (a.first == cur.first - 1 && a.second == cur.second + 1) possible = false;
    }
    if (possible) {
        cur.first--;
        cur.second++;
        return 1;
    }

    // Down and right
    possible = true;
    for (auto a : s) {
        if (a.first == cur.first + 1 && a.second == cur.second + 1) possible = false;
    }
    if (possible) {
        cur.first++;
        cur.second++;
        return 1;
    }

    if (cur.first == 500 && cur.second == 0) return -1;
    return 0;
}

void solve(string filename) {
    ifstream file(filename);
    string s;
    vector<string> parsed;
    vector<pair<int, int> > locations;
    int lowest = 0;

    while (getline(file, s)) {
        parsed = parse(s, " -> ");
        for (int i = 0; i < parsed.size() - 1; i++) {
            int x1 = stoi(parse(parsed[i], ",")[0]), y1 = stoi(parse(parsed[i], ",")[1]),
                x2 = stoi(parse(parsed[i + 1], ",")[0]), y2 = stoi(parse(parsed[i + 1], ",")[1]);
            // cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;

            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);

            for (int x = x1; x <= x2; x++) {
                for (int y = y1; y <= y2; y++) {
                    bool possible = true;
                    for (auto a : locations) {
                        if (a.first == x && a.second == y) {
                            possible = false;
                            break;
                        }
                    }
                    if (possible) locations.push_back(make_pair(x, y));
                    if (y > lowest) lowest = y;
                }
            }
        }
    }
    lowest++;
    for (int x = -1000; x <= 1000; x++) {
        locations.push_back(make_pair(x, lowest + 1));
    }

    int output = 0;
    pair<int, int> cur = make_pair(500, 0);
    while (true) {
        int status = move(locations, cur, lowest);
        if (status == 0) {
            locations.push_back(cur);
            cout << cur.first << " " << cur.second << endl;
            cur = make_pair(500, 0);
            output++;
        }
        else if (status == -1) {
            output++;
            break;
        }
    }
    cout << output << endl;

    file.close();
}

int main() {
    solve("14example.txt");
    solve("14input.txt");
}