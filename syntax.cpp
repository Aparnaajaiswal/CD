#include <iostream>
using namespace std;
struct Node {
    char value;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(char value) : value(value) {}
};
double evaluate(Node* node) {
    if (!node) return 0;
    if (!node->left && !node->right) return node->value - '0';

    double left = evaluate(node->left);
    double right = evaluate(node->right);

    switch (node->value) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
    }

    return 0;
}


int main() {
    Node nodes[] = { '+', '1', '*', '2', '3' };
    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];
    nodes[2].left = &nodes[3];
    nodes[2].right = &nodes[4];
    
cout << "Result: " << evaluate(nodes) << endl;

    return 0;
}
