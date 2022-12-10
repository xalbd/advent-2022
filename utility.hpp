#include <string>
#include <vector>
using namespace std;

vector<string> parse(string s, string delim) {
    vector<string> output;
    while (s.length() > 0) {
        int loc = s.find_first_of(delim);
        output.push_back(s.substr(0, loc));
        s.erase(0, (loc != string::npos) ? loc + 1 : string::npos);
    }
    return output;
}