#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    priority_queue<int> cal;
    string input;
    int cur = 0, out = 0;

    while (getline(cin, input)) {
        if (input != "" && input != "e") {
            cur += stoi(input);
        } else if (input == "e") {
            break;
        } else {
            cal.push(cur);
            cur = 0;
        }
    }

    cout << cal.top() << endl;
}