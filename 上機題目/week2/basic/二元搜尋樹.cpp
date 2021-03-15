#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *l, *r;
    Node () {
        l = r = nullptr;
    }
};

void build(Node *root, int &data) {
    if (root == nullptr) {
        root = new Node();
        root->data = data;
    }
    else {
        if (data > root->data) build(root->r, data);
        else build(root->l, data);
    }
}

void dfs(Node* root) {
    if (root == nullptr) return;
    dfs(root->l);
    dfs(root->r);
    cout << root->data << endl;
}

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int input;
    Node* root = nullptr;
    while (cin >> input) build(root, input);
    dfs(root);
}