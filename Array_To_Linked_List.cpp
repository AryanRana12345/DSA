#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* node;

        Node(int data1, Node* node1){
            data = data1;
            node = node1;
        }
        Node(int data1){
            data = data1;
            node = nullptr;
        }
};
Node* Converter(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1;i<arr.size();i++){
        Node* y = new Node(arr[i]);
        mover -> node = y;
        mover = mover->node;
    }
    return head;
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = Converter(arr);
    cout << head -> data;
}