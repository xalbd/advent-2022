#include <iostream>
#include <queue>
#include <string>
using namespace std;

#include <fstream>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

void solve(string filename) {
    ifstream file(filename);
    string s;
    priority_queue<int> cal;
    int cur = 0, output = 0;

    while (getline(file, s)) {
        if (s == "") {
            cal.push(cur);
            cur = 0;
        }
        else if (file.eof()) {
            cal.push(cur + stoi(s));
        }
        else {
            cur += stoi(s);
        }
    }

    for (int i = 0; i < 3; i++) {
        output += cal.top();
        cal.pop();
    }
    cout << output << endl;

    file.close();
}

int main() {
    solve("01example.txt");
    solve("01input.txt");
}