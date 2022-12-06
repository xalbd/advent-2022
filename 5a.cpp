#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

#include "utility.hpp"
using namespace std;

int main() {
    deque<char> boxes[10];
    string s;
    int count, start, end;
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
        getNext(s, count);
        getNext(s, start);
        getNext(s, end);
        for (int i = 0; i < count; i++) {
            boxes[end].push_front(boxes[start].front());
            boxes[start].pop_front();
        }
    }

    for (int i = 1; i <= 9; i++) cout << boxes[i].front();
    cout << endl;
}