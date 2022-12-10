#include <fstream>
#include <iostream>
#include <queue>
#include <string>

#include "../utility.hpp"
using namespace std;

void solve(string filename) {
    ifstream file(filename);
    string s;
    vector<string> parsed;
    int output = 0;

    while (getline(file, s)) {
        parsed = parse(s, "-,");
        if (!(stoi(parsed[1]) < stoi(parsed[2]) || stoi(parsed[0]) > stoi(parsed[3]))) output++;
    }
    cout << output << endl;

    file.close();
}

int main() {
    solve("04example.txt");
    solve("04input.txt");
}