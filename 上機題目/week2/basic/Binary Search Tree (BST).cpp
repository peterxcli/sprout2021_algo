#include <bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    Node *l, *r;
    Node() {
        l = r = nullptr;
    }
};

void build(Node *&root, int &data) {
    if (root == nullptr) {
        root = new Node();
        root->data = data;
    }
    else {
        if (data > root->data)
            build(root->r, data);
        else
            build(root->l, data);
    }
}

void dfs(Node *root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    dfs(root->l);
    dfs(root->r);
    
}

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int N, input;
    while (cin >> N) {
        Node *root = nullptr;
        for (int i = 0; i < N; i++) {
            cin >> input;
            build(root, input);
        }
        dfs(root);
        cout << "\n";
    }
}