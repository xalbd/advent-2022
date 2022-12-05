#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    string input;
    int out = 0;
    bool end = false;
    while (end == false) {
        int items[26 + 26 + 5][3] = {0};
        int a = 0;
        int b = 0;
        while (getline(cin, input)) {
            if (input == "") {
                end = true;
                break;
            }
            for (int a = 0; a < input.length(); a++) {
                if (islower(input[a])) {
                    items[input[a] - 'a' + 1][b]++;
                } else {
                    items[input[a] - 'A' + 26 + 1][b]++;
                }
            }
            b++;
            if (b == 3) break;
        }

        for (int i = 1; i < 26 + 26 + 5; i++) {
            if (items[i][0] > 0 && items[i][1] > 0 && items[i][2] > 0) {
                out += i;
                break;
            }
        }
    }

    cout << out << endl;
}
