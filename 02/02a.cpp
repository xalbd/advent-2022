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
        score += s[2] - 'X' + 1;

        if (s[2] - s[0] == 'X' - 'A') score += 3;
        if ((s[2] - s[0]) % 3 == ('Y' - 'A') % 3) score += 6;
    }
    cout << score << endl;

    file.close();
}

int main() {
    solve("02example.txt");
    solve("02input.txt");
}