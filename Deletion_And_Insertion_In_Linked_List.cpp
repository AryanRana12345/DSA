#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};
Node* Creation_Of_Linked_List(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}
int size(Node* head){
    if(head==NULL) return 0;
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt ++;
        temp = temp->next;
    }
    return cnt;
}
Node* Deletion_And_Insertion_In_Linked_List(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head -> next;
    delete temp;
    return head;
}
Node* Deletion_Of_Last_Element(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    Node* last_el = temp->next;
    temp->next = nullptr;
    delete last_el;
    return head;
}
Node* Deletion_Of_Kth_Element(Node* head, int k){
    if(head==NULL) return NULL;
    if(k<1 || k>size(head)) return head;
    if(k==1) return Deletion_And_Insertion_In_Linked_List(head);
    int cnt = 1;
    Node* temp = head;
    Node* previous = temp;
    while(cnt != k){
        previous = temp;
        temp=temp->next;
        cnt++;
    }
    Node* ahead = temp->next;
    previous->next = ahead;
    delete temp;
    return head;
}
Node* Deletion_Of_K_Value_Node(Node* head, int k){
    if(head == NULL) return head;
    Node* temp = head;
    Node* previous = NULL;
    if(head->data == k){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    while(temp->data != k && temp != NULL){
        previous = temp;
        temp = temp->next;
    }
    if(temp == NULL) return head;
    previous->next = temp->next;
    delete temp;
    return head;
}
void print(Node* head){
    if(head==NULL) cout << "Nothing here.";
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 3;
    Node* head = Creation_Of_Linked_List(arr);
    // head = Deletion_And_Insertion_In_Linked_List(head);
    // head = Deletion_Of_Last_Element(head);
    // head = Deletion_Of_Kth_Element(head,k);
    head = Deletion_Of_K_Value_Node(head,k);
    // size(head);
    print(head);
    return 0;
}