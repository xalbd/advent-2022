#include <string>
using namespace std;

bool getNext(string& s, int& output) {
    string valid = "0123456789";
    int start = s.find_first_of(valid), end = s.find_first_not_of(valid, start);
    if (s.length() == 0 || start == string::npos) return false;
    output = stoi(s.substr(start, (end != string::npos) ? (end - start) : end));
    s.erase(0, end);
    return true;
}

bool getNext(string& s, char& output) {
    string valid = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    int loc = s.find_first_of(valid);
    if (s.length() == 0 || loc == string::npos) return false;
    output = s.at(loc);
    s.erase(0, loc + 1);
    return true;
}

bool getNext(string& s, string& output) {
    string valid = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    int start = s.find_first_of(valid), end = s.find_first_not_of(valid, start);
    if (s.length() == 0 || start == string::npos) return false;
    output = s.substr(start, (end != string::npos) ? (end - start) : end);
    s.erase(0, end);
    return true;
}