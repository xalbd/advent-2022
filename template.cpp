#include <iostream>
#include <queue>
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
}