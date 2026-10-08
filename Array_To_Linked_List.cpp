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
    if(arr.size() == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1;i<arr.size();i++){
        Node* y = new Node(arr[i]);
        mover -> node = y;
        mover = mover->node;
    }
    return head;
}
int lengthofLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        temp = temp->node;
        cnt++;
    }
    return cnt;
}
bool Search_Element(Node* head, int target){
    Node* temp = head;
    while(temp){
        if(temp->data == target){
            return true;
        }
        temp = temp->node;
    }
    return false;
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = Converter(arr);
    Node* temp = head;
    while(temp){
        cout << temp->data;
        temp = temp->node;
    }
}