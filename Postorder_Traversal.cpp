#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data1, Node* left1 = nullptr, Node* right1 = nullptr){
        data = data1;
        left = left1;
        right = right1;
    }
};
void print(const Node* node){
    cout << node->data << " ";
}
void Postorder_Traversal(Node* node){
    if(node == nullptr) return;
    Postorder_Traversal(node->left);
    Postorder_Traversal(node->right);
    print(node);
}
void Delete_Tree(Node* node){
    if(node == nullptr) return;
    Delete_Tree(node->left);
    Delete_Tree(node->right);
    print(node);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(4);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    Postorder_Traversal(root);
}