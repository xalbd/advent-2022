#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

bool getNextSection(string& s, string delimiter, string& output) {
    // Utility function to grab next section of a string using a delimiter

    if (s.length() == 0) return false;
    output = s.substr(0, s.find(delimiter));
    s.erase(0, output.length() + delimiter.length());
    // cout << output << endl;
    return true;
}

int main() {
    deque<char> boxes[10];
    string s, count, start, end, dummy;
    int ci, si, ei;
    while (getline(cin, s)) {
        if (s == "") break;
        for (int i = 1; i <= 9; i++) {
            if (s.at(1 + (i - 1) * 4) != ' ') {
                boxes[i].push_back(s.at(1 + (i - 1) * 4));
            }
        }
    }

    cout << "input received" << endl;

    while (getline(cin, s)) {
        if (s == "") break;
        getNextSection(s, " ", dummy);
        getNextSection(s, " ", count);
        getNextSection(s, " ", dummy);
        getNextSection(s, " ", start);
        getNextSection(s, " ", dummy);
        getNextSection(s, " ", end);
        ci = stoi(count);
        si = stoi(start);
        ei = stoi(end);
        for (int i = 0; i < ci; i++) {
            boxes[ei].push_front(boxes[si].front());
            boxes[si].pop_front();
        }
    }

    for (int i = 1; i <= 9; i++) {
        cout << boxes[i].front();
    }
    cout << endl;
}