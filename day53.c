#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* buildTree() {
    int n;
    cin >> n;
    if (n == 0) return NULL;

    vector<int> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    Node* root = new Node(nodes[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < n) {
        Node* curr = q.front();
        q.pop();

        if (nodes[i] != -1) {
            curr->left = new Node(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if (i < n && nodes[i] != -1) {
            curr->right = new Node(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void verticalOrder(Node* root) {
    if (!root) return;

    map<int, vector<int>> m;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* curr = temp.first;
        int hd = temp.second;

        m[hd].push_back(curr->data);

        if (curr->left) q.push({curr->left, hd - 1});
        if (curr->right) q.push({curr->right, hd + 1});
    }

    for (auto const& [hd, values] : m) {
        for (int val : values) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    Node* root = buildTree();
    verticalOrder(root);
    return 0;
}
