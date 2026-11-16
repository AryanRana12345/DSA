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
void Level_Order_Traversal(Node* node){
    queue<Node*> que;
    que.push(node);
    while(que.empty() != true){
        Node* front_node = que.front();
        if(front_node != nullptr){
            que.push(front_node->left);
            que.push(front_node->right);
            cout << front_node->data << " ";
        }
        que.pop();
    }
}
void Delete_Tree(Node* node){
    if(node == nullptr) return;
    Delete_Tree(node->left);
    Delete_Tree(node->right);
    delete node;
}
int main(){
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(4);
    root->right->right = new Node(2);
    Level_Order_Traversal(root);
    Delete_Tree(root);
}