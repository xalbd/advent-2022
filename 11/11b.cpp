#include <deque>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#include "../utility.hpp"
using namespace std;

bool getNext(string& s, char& output) {
    string valid = "+*/-";
    int loc = s.find_first_of(valid);
    if (s.length() == 0 || loc == string::npos) return false;
    output = s.at(loc);
    s.erase(0, loc + 1);
    return true;
}

bool getNext(string& s, int& output) {
    string valid = "0123456789";
    int start = s.find_first_of(valid), end = s.find_first_not_of(valid, start);
    if (s.length() == 0 || start == string::npos) return false;
    output = stoi(s.substr(start, (end != string::npos) ? (end - start) : end));
    s.erase(0, end);
    return true;
}

// Gets next alphabetical string from an input string and deletes the part of string up to and including the string
bool getNext(string& s, string& output) {
    string valid = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM.";
    int start = s.find_first_of(valid), end = s.find_first_not_of(valid, start);
    if (s.length() == 0 || start == string::npos) return false;
    output = s.substr(start, (end != string::npos) ? (end - start) : end);
    s.erase(0, end);
    return true;
}

unsigned long long neededmod = 1;

unsigned long long operation(unsigned long long& worry, string op, string second, string divisible, string yesmonkey, string nomonkey) {
    if (op == "+")
        worry += (second == "old") ? worry : stoi(second);
    else if (op == "-")
        worry -= (second == "old") ? worry : stoi(second);
    else if (op == "*")
        worry *= (second == "old") ? worry : stoi(second);
    else if (op == "/")
        worry /= (second == "old") ? worry : stoi(second);

    worry = worry % neededmod;
    if (worry % stoi(divisible) == 0)
        return stoi(yesmonkey);
    else
        return stoi(nomonkey);
}

void solve(string filename) {
    ifstream file(filename);
    string s;
    vector<string> parsed;
    queue<unsigned long long> items[100];
    unsigned long long inspects[100] = {0};
    vector<vector<string> > instructions;
    unsigned long long index = 0;

    while (getline(file, s)) {
        int tempi;
        getline(file, s);
        while (getNext(s, tempi)) {
            items[index].push(tempi);
            cout << tempi << " ";
        }
        cout << endl;

        getline(file, s);
        vector<string> temp;
        string temps;
        char tempc;
        getNext(s, tempc);
        temps = tempc;
        temp.push_back(temps);
        getNext(s, temps);

        temp.push_back(temps);

        getline(file, s);
        getNext(s, tempi);
        temp.push_back(to_string(tempi));
        neededmod *= tempi;
        cout << "mod: " << neededmod << endl;

        getline(file, s);
        getNext(s, tempi);
        temp.push_back(to_string(tempi));

        getline(file, s);
        getNext(s, tempi);
        temp.push_back(to_string(tempi));

        instructions.push_back(temp);
        for (auto a : temp) cout << a << " ";
        cout << endl;

        getline(file, s);
        index++;
    }
    cout << "mod: " << neededmod << endl;

    for (unsigned long long i = 0; i < 10000; i++) {
        for (unsigned long long monkey = 0; monkey < index; monkey++) {
            while (items[monkey].size() > 0) {
                inspects[monkey]++;
                unsigned long long worry = items[monkey].front();
                unsigned long long toMonkey = operation(worry, instructions[monkey][0], instructions[monkey][1], instructions[monkey][2], instructions[monkey][3], instructions[monkey][4]);
                items[toMonkey].push(worry);
                items[monkey].pop();
            }
        }
    }

    unsigned long long a = 0, b = 0;
    for (auto value : inspects) {
        if (value > a) {
            b = a;
            a = value;
        }
        else if (value > b)
            b = value;
    }
    cout << a << " " << b << endl;
    cout << a * b << endl;

    file.close();
}

int main() {
    solve("11example.txt");
    neededmod = 1;
    solve("11input.txt");
}