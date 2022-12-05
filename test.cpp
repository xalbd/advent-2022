#include <iostream>
#include <string>
using namespace std;

int main() {
    string input = "QTRGNVF", output = "";
    for (int i = 0; i < input.length(); i++) {
        output += "'";
        output += input.at(i);
        output += "',";
    }
    cout << output;
}