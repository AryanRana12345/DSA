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
int helper(ListNode* temp){
    if(temp == nullptr){
        return 1;
    }
    int carry = helper(temp->next);
    if(carry == 0) return 0;
    temp->data = temp->data + carry;
    if(temp->data < 10){
        return 0;
    }
    temp->data = 0;
    return 1;
}
ListNode* Add_1_To_LL(ListNode* head){
    int carry = helper(head);
    if(carry == 1){
        ListNode* new_el = new ListNode(1);
        new_el->next = head;
        return new_el;
    }
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
    vector<int> arr = {9,9,9};
    ListNode* head = Array_To_Vector(arr);
    ListNode* new_head = Add_1_To_LL(head);
    Print(new_head);
}