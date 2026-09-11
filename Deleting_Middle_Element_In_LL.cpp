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
// 1 2 3 4 5
// 1 2 3 4
// s
// f
ListNode* Deleting_Middle_Element_In_LL(ListNode* head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* slow_tracker = nullptr;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow_tracker = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast->next == nullptr){
        slow_tracker->next = slow_tracker->next->next;
        slow->next = nullptr;
        delete slow;
        return head;
    }
    ListNode* del_el = slow->next;
    slow->next = slow->next->next;
    del_el->next = nullptr;
    delete del_el;
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
    vector<int> arr = {1};
    ListNode* head = Array_To_Vector(arr);
    ListNode* new_head = Deleting_Middle_Element_In_LL(head);
    Print(new_head);
}