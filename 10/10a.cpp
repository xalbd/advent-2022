#include <deque>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#include "../utility.hpp"
using namespace std;

int run(int &cycle, int x) {
    if ((cycle - 20) % 40 == 0 && cycle <= 220) {
        return (cycle++) * x;
    }
    cycle++;
    return 0;
}

void solve(string filename) {
    ifstream file(filename);
    string s;
    vector<string> parsed;
    int cycle = 1, x = 1, output = 0;
    while (getline(file, s)) {
        if (s == "") break;
        parsed = parse(s, " ");
        if (s == "noop") {
            output += run(cycle, x);
        }
        else {
            output += run(cycle, x);
            output += run(cycle, x);
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