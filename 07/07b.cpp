#include <deque>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#include "../utility.hpp"
using namespace std;

struct Node {
    Node(Node* p, string n, int s, bool d);
    void addSize(int s);
    int size;
    string name;
    vector<Node> children;
    Node* parent;
    bool isDirectory;
};

Node::Node(Node* p, string n, int s, bool d) {
    size = 0;
    name = n;
    parent = p;
    addSize(s);
    isDirectory = d;
}

void Node::addSize(int s) {
    this->size += s;
    if (this->parent == nullptr) return;
    parent->addSize(s);
}

int calc(Node* cur, int total) {
    int output;
    if (30000000 <= (70000000 - total + cur->size) && cur->isDirectory == true) {
        output = cur->size;
    }
    else {
        output = 70000000;
    }
    for (auto& child : cur->children) output = min(output, calc(&child, total));
    return output;
}

void solve(string filename) {
    ifstream file(filename);
    Node tree = Node(nullptr, "/", 0, true);
    Node* current = &tree;
    string s;
    vector<string> parsed;

    getline(file, s);
    while (getline(file, s)) {
        if (s == "") break;
        parsed = parse(s, " ");
        if (s.find("$ cd ..") != string::npos) {
            current = current->parent;
        }
        else if (s.find("$ cd") != string::npos) {
            for (auto& child : current->children) {
                if (child.name == parsed[2]) {
                    current = &child;
                    break;
                }
            }
        }
        else if (s.find("$ ls") != string::npos) {
            continue;
        }
        else if (s.find("dir ") != string::npos) {
            current->children.push_back(Node(current, parsed[1], 0, true));
        }
        else {
            current->children.push_back(Node(current, parsed[1], stoi(parsed[0]), false));
        }
    }
    cout << calc(&tree, tree.size) << endl;

    file.close();
}

int main() {
    solve("07example.txt");
    solve("07input.txt");
}