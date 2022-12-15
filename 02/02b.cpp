#include <fstream>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

void solve(string filename) {
    ifstream file(filename);
    string s;
    int score = 0;

    while (getline(file, s)) {
        if (s[2] == 'X') score += (s[0] - 'A' + 2) % 3 + 1;
        if (s[2] == 'Y') score += (s[0] - 'A' + 1) + 3;
        if (s[2] == 'Z') score += (s[0] - 'A' + 1) % 3 + 1 + 6;
    }
    cout << score << endl;

    file.close();
}

int main() {
    solve("02example.txt");
    solve("02input.txt");
}