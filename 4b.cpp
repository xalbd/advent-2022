#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int pos = 0;
    string s, current;
    string delimiter = "-";
    int values[4];
    int output = 0;
    while (getline(cin, s)) {
        if (s == "") break;
        delimiter = "-";
        int index = 0;
        while (pos = s.find(delimiter)) {
            current = s.substr(0, pos);
            // cout << current << endl;
            values[index] = stoi(current);
            index++;
            s.erase(0, pos + delimiter.length());
            if (delimiter == "-")
                delimiter = ",";
            else
                delimiter = "-";
            if (pos == string::npos) break;
        }
        if (!(values[1] < values[2] || values[0] > values[3])) output++;
    }
    cout << output;
}