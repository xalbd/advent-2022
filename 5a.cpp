#include <deque>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

#include "utility.hpp"
using namespace std;

void solve(string filename) {
    ifstream file(filename);
    deque<char> boxes[10];
    string s;
    vector<string> parsed;
    while (getline(file, s)) {
        cout << s << endl;
        if (s.length() == 0) break;
        if (s.find("1") != string::npos) continue;
        for (int i = 0; i * 4 + 1 < s.length(); i++) {
            if (s.at(i * 4 + 1) != ' ') {
                boxes[i].push_back(s.at(i * 4 + 1));
            }
        }
    }
    cout << "test";

    while (getline(file, s)) {
        if (s == "") break;
        parsed = parse(s, " ");
        for (int i = 0; i < stoi(parsed[1]); i++) {
            boxes[stoi(parsed[5]) - 1].push_front(boxes[stoi(parsed[3]) - 1].front());
            boxes[stoi(parsed[3]) - 1].pop_front();
        }
    }

    for (int i = 0; i < 9; i++) cout << boxes[i].front();
    cout << endl;
    file.close();
}

int main() {
    solve("5example.txt");
    solve("5input.txt");
}