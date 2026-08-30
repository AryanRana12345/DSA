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
int Size_List(Node* head);
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
Node* deleting_head_of_list(Node* head){
    if(head == NULL) return NULL;
    Node* temp = head->next;
    head->next = NULL;
    delete head;
    return temp;
}
Node* inserting_head_of_list(Node* head, int num){
    Node* new_el = new Node(num);
    new_el->next = head;
    return new_el;
}
void Print_List(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " "; 
        temp = temp->next;
    }
    cout << endl;
}
int Size_List(Node* head){
    Node* temp = head;
    int i=0;
    while(temp != NULL){
        i++;
        temp = temp->next;
    }
    return i;
}
int main(){
    vector<int> arr = {};
    Node* head = Array_To_List(arr);
    Print_List(head);
    Node* list_with_deleted_head = deleting_head_of_list(head);
    Print_List(list_with_deleted_head);
    int num;
    cout << "Enter the new head of the list: ";
    cin >> num;
    Node* list_with_newly_inserted_head = inserting_head_of_list(list_with_deleted_head,num);
    Print_List(list_with_newly_inserted_head);
    cout << "Size of List: " << Size_List(list_with_newly_inserted_head);
}