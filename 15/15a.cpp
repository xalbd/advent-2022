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

void solve(string filename, int coor) {
    ifstream file(filename);
    string s;
    vector<string> parsed;
    set<int> visit;
    set<int> unfortunate;
    int out = 0;

    while (getline(file, s)) {
        parsed = parse(s, " ");
        int x, y, bx, by;
        x = stoi(parsed[2].substr(2, parsed[2].length() - 1));
        y = stoi(parsed[3].substr(2, parsed[3].length() - 1));
        bx = stoi(parsed[8].substr(2, parsed[8].length() - 1));
        by = stoi(parsed[9].substr(2, parsed[9].length()));
        // cout << x << y << bx << by << endl;
        if (by == coor) {
            unfortunate.insert(bx);
        }

        int dist = abs(bx - x) + abs(by - y);

        int newbx = x;
        while (abs(newbx - x) + abs(coor - y) <= dist) {
            if (visit.find(newbx) == visit.end()) {
                visit.insert(newbx);
                // cout << newbx << endl;
            }

            newbx++;
        }
        newbx = x - 1;
        while (abs(newbx - x) + abs(coor - y) <= dist) {
            if (visit.find(newbx) == visit.end()) {
                visit.insert(newbx);
                // cout << newbx << endl;
            }
            newbx--;
        }
    }
    int torem = 0;
    for (auto a : unfortunate) {
        if (visit.find(a) != visit.end()) torem++;
    }
    cout << visit.size() << " " << torem << endl;
    cout << visit.size() - torem << endl;

    file.close();
}

int main() {
    solve("15example.txt", 10);
    solve("15input.txt", 2000000);
}