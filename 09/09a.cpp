#include <deque>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#include "../utility.hpp"
using namespace std;

struct location {
    int x;
    int y;
};

void moveTail(location h, location& t) {
    if (abs(h.x - t.x) <= 1 && abs(h.y - t.y) <= 1) return;
    if (h.x - t.x == 2) {
        t.x = h.x - 1;
        t.y = h.y;
    }
    else if (t.x - h.x == 2) {
        t.x = h.x + 1;
        t.y = h.y;
    }
    else if (h.y - t.y == 2) {
        t.y = h.y - 1;
        t.x = h.x;
    }
    else if (t.y - h.y == 2) {
        t.y = h.y + 1;
        t.x = h.x;
    }
}

void solve(string filename) {
    ifstream file(filename);
    string s;
    vector<string> parsed;
    location h, t;
    vector<location> visited;
    int output = 0;
    while (getline(file, s)) {
        if (s == "") break;
        parsed = parse(s, " ");
        string direction = parsed[0];
        int amount = stoi(parsed[1]);

        for (int i = 0; i < amount; i++) {
            if (direction == "U") {
                h.y++;
            }
            else if (direction == "D") {
                h.y--;
            }
            else if (direction == "L") {
                h.x--;
            }
            else if (direction == "R") {
                h.x++;
            }
            moveTail(h, t);
            bool valid = true;
            for (auto loc : visited) {
                if (loc.x == t.x && loc.y == t.y) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                visited.push_back(t);
                output++;
            }
        }
    }
    cout << output << endl;
    file.close();
}

int main() {
    solve("09example.txt");
    solve("09input.txt");
}