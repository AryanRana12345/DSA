#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int data1, Node* left1 = nullptr, Node* right1 = nullptr){
        data = data1;
        left = left1;
        right = right1;
    }
};
void print(Node* node){
    cout << node->data << " ";
}
void Pre_Order_Traversal(Node* node){
    if(node == nullptr) return;
    print(node);
    Pre_Order_Traversal(node->left);
    Pre_Order_Traversal(node->right);
}
int main(){
    struct Node* root = new Node(1);
    root->left = new Node(4);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    Pre_Order_Traversal(root);
}