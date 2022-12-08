#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    string input;
    int out = 0;
    bool end = false;
    while (getline(cin, input)) {
        if (input == "") break;
        int items[26 + 26 + 5] = {0}, items2[26 + 26 + 5] = {0};
        int a = 0;
        int b = input.length() - 1;
        while (a < b) {
            if (islower(input[a])) {
                items[input[a] - 'a' + 1]++;
            } else
                items[input[a] - 'A' + 26 + 1]++;
            if (islower(input[b])) {
                items2[input[b] - 'a' + 1]++;
            } else
                items2[input[b] - 'A' + 26 + 1]++;

            a++;
            b--;
        }
        for (int i = 1; i < 26 + 26 + 5; i++) {
            if (items[i] > 0 && items2[i] > 0) {
                out += i;
                break;
            }
        }
    }

    cout << out << endl;
}