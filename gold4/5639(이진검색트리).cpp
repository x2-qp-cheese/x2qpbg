#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr){};
};

Node* insert(Node* tree, int val){
    if(tree == nullptr){
        return new Node(val);
    }
    if(val < tree->data){
        tree->left = insert(tree->left, val);
    }else{
        tree->right = insert(tree->right, val);
    }
    return tree;
}

void postorder(Node* tree){
    if(tree == nullptr) return;
    postorder(tree->left);
    postorder(tree->right);
    cout << tree->data << endl;
}

int main(){;
    Node* root = nullptr;
    int n;
    while(cin >> n){
        root = insert(root, n);
    }

    postorder(root);
}
