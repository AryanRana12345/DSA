#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
        int data;
        ListNode* next;
        ListNode(int data1,ListNode* next1 = nullptr){
            data = data1;
            next = next1;
        }
};
ListNode* Array_To_Vector(vector<int> arr){
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for(int i = 1;i<arr.size();i++){
        ListNode* element = new ListNode(arr[i]);
        temp->next = element;
        temp=temp->next;
    }
    return head;
}
// {1,2,3,4,5,6,7,8}
ListNode* Removing_Node(ListNode* head, int pos){
    if(pos <= 0) return head;
    ListNode* ahead = head;
    for(int i = 0;i<pos;i++){
        ahead = ahead->next;
        if(ahead == nullptr) return head;
    }
    if(ahead->next == nullptr) return head->next;
    ListNode* behind = head;
    while(ahead->next != nullptr){
        ahead = ahead->next;
        behind = behind->next;
    }
    ListNode* delNode = behind->next;
    behind->next = behind->next->next;
    delNode->next = nullptr;
    delete delNode;
    return head;
}
void Print(ListNode* head){
    ListNode* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    ListNode* head = Array_To_Vector(arr);
    int position = 6;
    ListNode* new_head = Removing_Node(head,position);
    Print(new_head);
}