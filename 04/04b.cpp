#include <iostream>
#include <queue>
#include <string>

#include "../utility.hpp"
using namespace std;

int main() {
    string s;
    int values[4], output = 0;
    while (getline(cin, s)) {
        if (s == "") break;
        for (int i = 0; i < 4; i++) {
            getNext(s, values[i]);
        }
        if (!(values[1] < values[2] || values[0] > values[3])) output++;
    }

    cout << output << endl;
}