#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

#include "../utility.hpp"
using namespace std;

int main() {
    deque<char> boxes[10];
    string s;
    int count, start, end;
    while (getline(cin, s)) {
        if (s == "") break;
        if (s.find("1") != string::npos) continue;
        for (int i = 1; i <= 9; i++) {
            if (s.at(1 + (i - 1) * 4) != ' ') {
                boxes[i].push_back(s.at(1 + (i - 1) * 4));
            }
        }
    }

    while (getline(cin, s)) {
        if (s == "") break;
        getNext(s, count);
        getNext(s, start);
        getNext(s, end);
        deque<char> temp;

        for (int i = 0; i < count; i++) {
            temp.push_back(boxes[start].front());
            boxes[start].pop_front();
        }

        for (int i = 0; i < count; i++) {
            boxes[end].push_front(temp.back());
            temp.pop_back();
        }
    }

    for (int i = 1; i <= 9; i++) cout << boxes[i].front();
    cout << endl;
}