#include <deque>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

#include "../utility.hpp"
using namespace std;

void solve(string filename) {
    ifstream file(filename);
    deque<char> boxes[10];
    string s;
    vector<string> parsed;
    int total;
    while (getline(file, s)) {
        if (s.length() == 0) break;
        if (s.find("1") != string::npos) continue;
        for (total = 0; total * 4 + 1 < s.length(); total++) {
            if (s.at(total * 4 + 1) != ' ') {
                boxes[total].push_back(s.at(total * 4 + 1));
            }
        }
    }

    while (getline(file, s)) {
        if (s == "") break;
        parsed = parse(s, " ");
        for (int i = 0; i < stoi(parsed[1]); i++) {
            boxes[stoi(parsed[5]) - 1].push_front(boxes[stoi(parsed[3]) - 1].front());
            boxes[stoi(parsed[3]) - 1].pop_front();
        }
    }

    for (int i = 0; i < total; i++) cout << boxes[i].front();
    cout << endl;
    file.close();
}

int main() {
    solve("05example.txt");
    solve("05input.txt");
}