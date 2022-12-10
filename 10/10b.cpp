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
    vector<string> parsed;
    int cycle = 1, x = 1, output = 0, checked = 0;
    char crt[41][6];
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 6; j++) {
            crt[i][j] = '.';
        }
    }
    while (getline(file, s)) {
        if (s == "") break;
        parsed = parse(s, " ");
        if (s == "noop") {
            if (cycle - 1 < 240) {
                if (abs(((cycle - 1) % 40) - (x)) <= 1) crt[(cycle - 1) % 40][(cycle - 1) / 40] = '#';
            }
            cycle++;
            continue;
        }
        else {
            if (cycle - 1 < 240) {
                if (abs(((cycle - 1) % 40) - (x)) <= 1) crt[(cycle - 1) % 40][(cycle - 1) / 40] = '#';
            }
            cycle++;

            if (cycle - 1 < 240) {
                if (abs(((cycle - 1) % 40) - (x)) <= 1) crt[(cycle - 1) % 40][(cycle - 1) / 40] = '#';
            }
            cycle++;
            x += stoi(parsed[1]);
        }
    }
    for (int j = 0; j < 6; j++) {
        for (int i = 0; i < 41; i++) {
            cout << crt[i][j];
        }
        cout << endl;
    }

    file.close();
}

int main() {
    solve("10example.txt");
    cout << endl;
    solve("10input.txt");
}