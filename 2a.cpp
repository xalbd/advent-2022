#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    string in;
    int score = 0;
    while (getline(cin, in)) {
        if (in.length() != 3) break;

        if (in[2] == 'X')
            score++;
        else if (in[2] == 'Y')
            score += 2;
        else if (in[2] == 'Z')
            score += 3;

        if (in[0] == in[2] - ('X' - 'A')) {
            score += 3;
        }
        if (in[0] == 'A' && in[2] == 'Y') score += 6;
        if (in[0] == 'B' && in[2] == 'Z') score += 6;
        if (in[0] == 'C' && in[2] == 'X') score += 6;
        cout << score << endl;
    }
}