#include <string>
using namespace std;

// Gets next int from an input string and deletes the part of string up to and including the int
bool getNext(string& s, int& output) {
    string valid = "0123456789";
    int start = s.find_first_of(valid), end = s.find_first_not_of(valid, start);
    if (s.length() == 0 || start == string::npos) return false;
    output = stoi(s.substr(start, (end != string::npos) ? (end - start) : end));
    s.erase(0, end);
    return true;
}

// Gets next alphabetical char from an input string and deletes the part of string up to and including the char
bool getNext(string& s, char& output) {
    string valid = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    int loc = s.find_first_of(valid);
    if (s.length() == 0 || loc == string::npos) return false;
    output = s.at(loc);
    s.erase(0, loc + 1);
    return true;
}

// Gets next alphabetical string from an input string and deletes the part of string up to and including the string
bool getNext(string& s, string& output) {
    string valid = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    int start = s.find_first_of(valid), end = s.find_first_not_of(valid, start);
    if (s.length() == 0 || start == string::npos) return false;
    output = s.substr(start, (end != string::npos) ? (end - start) : end);
    s.erase(0, end);
    return true;
}