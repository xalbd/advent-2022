#include <fstream>
#include <iostream>
#include <queue>
#include <string>

#include "utility.hpp"
using namespace std;

void solve(string filename) {
    ifstream file(filename);
    string s;
    file >> s;
    for (int i = 0; i < s.length(); i++) {
        bool valid = true;
        for (int j = 0; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                if (s[i + j] == s[i + k]) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            cout << i + 4 << endl;
            break;
        }
    }
    file.close();
}

int main() {
    solve("6example.txt");
    solve("6input.txt");
}