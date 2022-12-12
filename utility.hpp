#include <string>
#include <vector>
using namespace std;

vector<string> parse(string s, string delim) {
    vector<string> output;
    while (s.length() > 0) {
        int start = s.find_first_not_of(delim), end = s.find_first_of(delim, start);
        output.push_back(s.substr(start, end - start));
        s.erase(0, (end != string::npos) ? end + 1 : string::npos);
    }
    return output;
}