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
    while (getline(file, s)) {
        if (s == "") break;
        parsed = parse(s, " ");
        if (s == "noop") {
                        if ((cycle - 20) % 40 == 0 && checked < 6) {
                output += cycle * x;
                checked++;
            }
            cycle++;
            continue;
        }
        else {
            if ((cycle - 20) % 40 == 0 && checked < 6) {
                output += cycle * x;
                checked++;
            }
            cycle++;

            if ((cycle - 20) % 40 == 0 && checked < 6) {
                output += cycle * x;
                checked++;
            }
            cycle++;
            x += stoi(parsed[1]);
        }
    }
    cout << output << endl;
    file.close();
}

int main() {
    solve("10example.txt");
    solve("10input.txt");
}