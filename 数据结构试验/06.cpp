#include <iostream>
#include <stack>

using namespace std;

struct Node {
    char data;
    /// l×ó¶ù×Ó£¬rÓÒ¶ù×Ó.
    Node* l;
    Node* r;
    Node(char data, Node* l=NULL, Node* r=NULL) :
        data(data), l(l), r(r) {}
};

void raw_build(Node*& root) {
    root = new Node('A');
    root->l = new Node('B');
    root->r = new Node('C');
    root->l->r = new Node('D');
    root->r->r = new Node('E');
    root->l->l = new Node('F');
    root->l->l->r = new Node('G');
}

void lrd(Node* root) {
    if (root == NULL) return;
    lrd(root->l);
    lrd(root->r);
    cout << "[" << root->data << "]";
}

void lrd_stack(Node* root) {
    stack<Node*> s;
    stack<char> flag;
    while (!s.empty() || root != NULL) {
        if (root != NULL) {
            s.push(root);
            flag.push(1);
            root = root->l;
        } else {
            if (!s.empty() && flag.top() == 2) {
                Node* d = s.top();
                cout << "[" << d->data << "]";
                flag.pop();
                s.pop();
            } else if (!s.empty()) {
                flag.pop();
                flag.push(2);
                root = s.top()->r;
            }
        }
    }
}

int main() {
    Node* root;
    raw_build(root);
    cout << "µÝ¹éËã·¨£º" << endl;
    lrd(root); cout << endl;
    cout << "·ÇµÝ¹éËã·¨£º" << endl;
    lrd_stack(root); cout << endl;
    return 0;
}
