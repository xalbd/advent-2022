#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;

void solve(string filename) {
    ifstream file(filename);
    string s;
    int out = 0;

    while (getline(file, s)) {
        for (auto a : s.substr(0, s.length() / 2)) {
            if (s.find(a, s.length() / 2) != string::npos) {
                if (a >= 'a') {
                    out += a - 'a' + 1;
                }
                else {
                    out += a - 'A' + 26 + 1;
                }
                break;
            }
        }
    }
    cout << out << endl;

    file.close();
}

int main() {
    solve("03example.txt");
    solve("03input.txt");
}