#include <deque>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#include "../utility.hpp"
using namespace std;

void run(int &cycle, int x) {  // x: 0-39, cycle: 1-40
    if (cycle % 40 == 1) cout << endl;
    cycle--;
    if (abs((cycle % 40) - x) <= 1 && cycle < 240) {
        cout << "#";
    }
    else {
        cout << " ";
    }
    cycle += 2;
}

void solve(string filename) {
    ifstream file(filename);
    string s;
    vector<string> parsed;
    int cycle = 1, x = 1;

    while (getline(file, s)) {
        if (s == "") break;
        parsed = parse(s, " ");
        if (s == "noop") {
            run(cycle, x);
        }
        else {
            run(cycle, x);
            run(cycle, x);
            x += stoi(parsed[1]);
        }
    }

    file.close();
}

int main() {
    solve("10example.txt");
    solve("10input.txt");
}