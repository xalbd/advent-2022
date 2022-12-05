#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Utility function to grab next section of a string using a delimiter to find end
// If reaches EOS, s.substr grabs rest of string as s.find returns string::npos
// Returns false if string is empty and true if s and output are changed
bool getNextSection(string& s, string delimiter, string& output) {
    if (s == "") return false;
    output = s.substr(0, s.find(delimiter));
    s.erase(0, s.find(delimiter) + delimiter.length());
    // cout << output << endl;
    return true;
}

int main() {
    string input = "2-4,6-8", output;
    getNextSection(input, "-", output);
    cout << output;
    getNextSection(input, ",", output);
    cout << output;
    getNextSection(input, "-", output);
    cout << output;
    getNextSection(input, "-asfskdfjlkzsjdf", output);
    cout << output;
    cout << getNextSection(input, "-asfskdfjlkzsjdf", output) << endl;
}