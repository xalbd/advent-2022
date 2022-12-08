#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    string in;
    int score = 0;
    while (getline(cin, in)) {
        if (in.length() != 3) break;

        if (in[2] == 'Y') score += in[0] - 'A' + 1 + 3;
        if (in[2] == 'Z') {
            score += 6;
            if (in[0] == 'A')
                score += 2;
            else if (in[0] == 'B')
                score += 3;
            else if (in[0] == 'C')
                score += 1;
        }
        if (in[2] == 'X') {
            if (in[0] == 'A')
                score += 3;
            else if (in[0] == 'B')
                score += 1;
            else if (in[0] == 'C')
                score += 2;
        }
        cout << score << endl;
    }
}