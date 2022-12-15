#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;

void solve(string filename) {
    ifstream file(filename);
    string x, y, z;
    int out = 0;

    while (getline(file, x)) {
        getline(file, y);
        getline(file, z);
        for (auto a : x) {
            if (y.find(a) != string::npos && z.find(a) != string::npos) {
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