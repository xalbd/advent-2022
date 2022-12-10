#include <deque>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#include "../utility.hpp"
using namespace std;

void run(int &cycle, int x, char crt[6][40]) {  // x: 0-39, cycle: 1-40
    cycle--;
    if (abs((cycle % 40) - x) <= 1 && cycle < 240)
        crt[cycle / 40][cycle % 40] = '#';
    cycle += 2;
}

void solve(string filename) {
    ifstream file(filename);
    string s;
    vector<string> parsed;
    int cycle = 1, x = 1;
    char crt[6][40];
    for (auto &a : crt) {
        for (auto &b : a) {
            b = ' ';
        }
    }
    while (getline(file, s)) {
        if (s == "") break;
        parsed = parse(s, " ");
        if (s == "noop") {
            run(cycle, x, crt);
        }
        else {
            run(cycle, x, crt);
            run(cycle, x, crt);
            x += stoi(parsed[1]);
        }
    }
    for (auto &a : crt) {
        for (auto &b : a) {
            cout << b;
        }
        cout << endl;
    }
    cout << endl;
    file.close();
}

int main() {
    solve("10example.txt");
    solve("10input.txt");
}