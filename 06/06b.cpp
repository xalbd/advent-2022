#include <fstream>
#include <iostream>
#include <queue>
#include <string>

#include "../utility.hpp"
using namespace std;

void solve(string filename) {
    ifstream file(filename);
    string s;
    file >> s;
    for (int i = 0; i < s.length(); i++) {
        bool valid = true;
        for (int j = 0; j < 14; j++) {
            for (int k = j + 1; k < 14; k++) {
                if (s[i + j] == s[i + k]) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            cout << i + 14 << endl;
            break;
        }
    }
    file.close();
}

int main() {
    solve("06example.txt");
    solve("06input.txt");
}