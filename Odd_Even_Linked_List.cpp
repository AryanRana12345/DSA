#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
        int data;
        ListNode* next;
        ListNode(int data1, ListNode* next1 = nullptr){
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
ListNode* Odd_Even_Linked_List(ListNode* head){
    ListNode* temp1 = head;
    ListNode* odd_head = temp1;
    ListNode* temp2 = head->next;
    ListNode* even_head = temp2;
    while(temp1->next != nullptr && temp2->next != nullptr){
        temp1->next = temp1->next->next;
        temp1 = temp1->next;
        temp2->next = temp2->next->next;
        temp2 = temp2->next;
    }
    temp1->next = even_head;
    temp2->next = nullptr;
    return odd_head;
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
    ListNode* new_head = Odd_Even_Linked_List(head);
    Print(new_head);
}