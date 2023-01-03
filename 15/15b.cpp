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

int dist(int x, int y, int x1, int y1) {
    return abs(y1 - y) + abs(x1 - x);
}

bool check(int x, int y, vector<vector<int> > info, int l) {
    if (!(x >= 0 && x <= l && y >= 0 && y <= l)) return false;
    for (auto a : info) {
        if (dist(x, y, a[0], a[1]) <= a[2]) {
            return false;
        }
    }
    return true;
}

void solve(string filename, int coor) {
    ifstream file(filename);
    string s;
    vector<string> parsed;
    vector<vector<int> > info;

    while (getline(file, s)) {
        parsed = parse(s, " ");
        int x, y, bx, by;
        x = stoi(parsed[2].substr(2, parsed[2].length() - 1));
        y = stoi(parsed[3].substr(2, parsed[3].length() - 1));
        bx = stoi(parsed[8].substr(2, parsed[8].length() - 1));
        by = stoi(parsed[9].substr(2, parsed[9].length()));

        int dist = abs(bx - x) + abs(by - y);
        vector<int> temp;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(dist);
        info.push_back(temp);
    }
    for (auto a : info) {
        int newx, newy;

        newx = a[0] + a[2] + 1, newy = a[1];
        while (dist(a[0], a[1], newx, newy) == a[2] + 1) {
            if (check(newx, newy, info, coor)) {
                cout << newx * 4000000 + newy << endl;
                return;
            }
            newx--;
            newy--;
        }

        newx = a[0] + a[2] + 1, newy = a[1];
        while (dist(a[0], a[1], newx, newy) == a[2] + 1) {
            if (check(newx, newy, info, coor)) {
                cout << newx * 4000000 + newy << endl;
                return;
            }
            newx--;
            newy++;
        }

        newx = a[0] - a[2] - 1, newy = a[1];
        while (dist(a[0], a[1], newx, newy) == a[2] + 1) {
            if (check(newx, newy, info, coor)) {
                cout << newx * 4000000 + newy << endl;
                return;
            }
            newx++;
            newy--;
        }

        newx = a[0] - a[2] - 1, newy = a[1];
        while (dist(a[0], a[1], newx, newy) == a[2] + 1) {
            if (check(newx, newy, info, coor)) {
                cout << newx * 4000000 + newy << endl;
                return;
            }
            newx++;
            newy++;
        }
    }

    file.close();
}

int main() {
    // solve("15example.txt", 20);
    solve("15input.txt", 4000000);
}