#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#include "utility.hpp"
using namespace std;

struct Node {
    Node(Node* p, string s);
    Node(Node* p, string s, int size);
    void addSize(int s);
    int size;
    string name;
    vector<Node> children;
    Node* parent;
    bool isDirectory;
};

Node::Node(Node* p, string s) {
    size = 0;
    name = s;
    parent = p;
    isDirectory = true;
}

Node::Node(Node* p, string s, int si) {
    size = 0;
    name = s;
    parent = p;
    addSize(si);
    isDirectory = false;
}

void Node::addSize(int s) {
    this->size += s;
    if (this->parent == nullptr) return;
    parent->addSize(s);
}

void calc(Node* cur, int& output, int needed) {
    for (int i = 0; i < cur->children.size(); i++) {
        Node* child = &cur->children[i];
        if (child->size >= needed && child->isDirectory == true && child->size < output) {
            output = child->size;
        }
        calc(child, output, needed);
    }
}

int main() {
    Node tree = Node(nullptr, "");
    Node* current = &tree;
    tree.children.push_back(Node(&tree, "/"));
    string s, name;
    int size;
    getline(cin, s);  // Created root already
    while (getline(cin, s)) {
        if (s == "") break;
        if (s.find("$ cd ..") != string::npos) {
            current = current->parent;
        } else if (s.find("$ cd") != string::npos) {
            name = s.substr(5, string::npos);
            for (int i = 0; i < current->children.size(); i++) {
                Node* child = &current->children[i];
                if (child->name == name) {
                    current = child;
                    break;
                }
            }
        } else if (s.find("$ ls") != string::npos) {
            continue;
        } else {
            if (s.find("dir ") != string::npos) {
                name = s.substr(4, string::npos);
                current->children.push_back(Node(current, name));
            } else {
                getNext(s, size);
                getNext(s, name);
                current->children.push_back(Node(current, name, size));
            }
        }
    }

    int needed = 30000000 - (70000000 - tree.size), output = 70000000;
    cout << needed << endl;
    calc(&tree, output, needed);
    cout << output << endl;
}