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
        t.x++;
        if (t.y > h.y)
            t.y--;
        else if (t.y < h.y)
            t.y++;
    }
    if (t.x - h.x == 2) {
        t.x--;
        if (t.y > h.y)
            t.y--;
        else if (t.y < h.y)
            t.y++;
    }
    if (h.y - t.y == 2) {
        t.y++;
        if (t.x > h.x)
            t.x--;
        else if (t.x < h.x)
            t.x++;
    }
    if (t.y - h.y == 2) {
        t.y--;
        if (t.x > h.x)
            t.x--;
        else if (t.x < h.x)
            t.x++;
    }
}

void moveHead(location& h, string direction) {
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
}

void solve(string filename) {
    ifstream file(filename);
    string s;
    vector<string> parsed;
    vector<location> visited;
    int output = 0;
    vector<location> molecules;
    for (int i = 0; i < 10; i++) {
        location temp;
        temp.x = 0;
        temp.y = 0;
        molecules.push_back(temp);
    }
    while (getline(file, s)) {
        if (s == "") break;
        parsed = parse(s, " ");
        string direction = parsed[0];
        int amount = stoi(parsed[1]);

        for (int i = 0; i < amount; i++) {
            moveHead(molecules[0], direction);
            for (int j = 1; j < 10; j++) {
                moveTail(molecules[j - 1], molecules[j]);
            }

            bool valid = true;
            for (auto loc : visited) {
                if (loc.x == molecules[9].x && loc.y == molecules[9].y) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                visited.push_back(molecules[9]);
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