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
    Node(Node* p, string r);
    int value;
    string raw;
    vector<Node> children;
    Node* parent;
};

Node::Node(Node* p, string r) {
    raw = r;
    parent = p;
}

void solve(string filename) {
    ifstream file(filename);
    string s;
    vector<string> parsed;
    int index = 1, output = 0;

    while (getline(file, s)) {
        Node parent1 = Node(nullptr), parent2 = Node(nullptr);

        // Parse first string
        for (int i = 0; i < s.length(); i++) {
        }

        getline(file, s);
        // Parse second string

        if (order(parent1, parent2)) {
            output += index;
        }
        index++;
        getline(file, s);  // Waste empty line
    }

    file.close();
}

int main() {
    solve("example.txt");
    solve("input.txt");
}