#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#include "utility.hpp"
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

int calc(Node* cur) {
    int out;
    if (30000000 <= (70000000 - cur->size) && cur->isDirectory == true) {
        out = cur->size;
    }
    else {
        out = 70000000;
    }
    for (auto& child : cur->children) out = min(out, calc(&child));
    return out;
}

int main() {
    Node tree = Node(nullptr, "/", 0, true);
    Node* current = &tree;
    string s;
    int size;
    getline(cin, s);
    while (getline(cin, s)) {
        if (s == "") break;
        if (s.find("$ cd ..") != string::npos) {
            current = current->parent;
        }
        else if (s.find("$ cd") != string::npos) {
            for (auto& child : current->children) {
                if (child.name == s.substr(5, string::npos)) {
                    current = &child;
                    break;
                }
            }
        }
        else if (s.find("$ ls") != string::npos) {
            continue;
        }
        else if (s.find("dir ") != string::npos) {
            current->children.push_back(Node(current, s.substr(4, string::npos), 0, true));
        }
        else {
            current->children.push_back(Node(current, parse(s, " ")[1], stoi(parse(s, " ")[0]), false));
        }
    }

    cout << calc(&tree) << endl;
}