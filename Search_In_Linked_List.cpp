#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data1){
            data = data1;
            next = NULL;
        }
};
Node* Array_To_List(vector<int>& arr){
    if(arr.size() == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1;i<arr.size();i++){
        Node* new_el = new Node(arr[i]);
        temp->next = new_el;
        temp = temp->next;
    }
    return head;
}
bool search_element(Node* head, int num){
    Node* temp = head;
    while(temp!= NULL){
        if(temp->data == num) return true;
        temp=temp->next;
    }
    return false;
}
int main(){
    int num;
    cout << "Enter Element: ";
    cin >> num;
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = Array_To_List(arr);
    cout << search_element(head,num);
}