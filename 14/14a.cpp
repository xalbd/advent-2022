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

bool hasBottom(set<pair<int, int> > s, int x) {
    for (auto a : s) {
        if (a.first == x) return true;
    }
    return false;
}

int move(set<pair<int, int> > s, pair<int, int> &cur) {
        // Straight down
    if (s.find(make_pair(cur.first, cur.second + 1)) == s.end()) {
        if (!hasBottom(s, cur.first)) return -1;
        cur.second++;
        return 1;
    }

    // Down and left
    if (s.find(make_pair(cur.first - 1, cur.second + 1)) == s.end()) {
        cur.first--;
        cur.second++;
        return 1;
    }

    // Down and right
    if (s.find(make_pair(cur.first + 1, cur.second + 1)) == s.end()) {
        cur.first++;
        cur.second++;
        return 1;
    }

    return 0;
}

void solve(string filename) {
    ifstream file(filename);
    string s;
    vector<string> parsed;
    set<pair<int, int> > locations;

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
                    locations.insert(make_pair(x, y));
                }
            }
        }
    }

    int output = 0;
    pair<int, int> cur = make_pair(500, 0);
    while (true) {
        int status = move(locations, cur);
        if (status == 0) {
            locations.insert(cur);
            // cout << cur.first << " " << cur.second << endl;
            cur = make_pair(500, 0);
            output++;
        }
        else if (status == -1) {
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