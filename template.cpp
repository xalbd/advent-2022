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

    while (getline(file, s)) {
        parsed = parse(s, " ");
    }

    file.close();
}

int main() {
    solve("example.txt");
    solve("input.txt");
}