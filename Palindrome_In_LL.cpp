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
bool Palindrome_In_LL(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* temp = slow->next;
    ListNode* prev = nullptr;
    while(temp != nullptr){
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    ListNode* comp_head = head;
    ListNode* cons_head = prev;
    while(prev != nullptr){
        if(comp_head->data != prev->data){
            ListNode* temp1 = cons_head;
            ListNode* prev1 = nullptr;
            while(temp1 != nullptr){
                ListNode* front1 = temp1->next;
                temp1->next = prev1;
                prev1 = temp1;
                temp1 = front1;
            }
            return false;
        }
        comp_head = comp_head->next;
        prev = prev->next;
    }
    ListNode* temp2 = cons_head;
    ListNode* prev2 = nullptr;
    while(temp2 != nullptr){
        ListNode* front2 = temp2->next;
        temp2->next = prev2;
        prev2 = temp2;
        temp2 = front2;
    }
    return true;
}
void Print(ListNode* head){
    ListNode* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main(){
    vector<int> arr = {1,2,3,3,2,2};
    ListNode* head = Array_To_Vector(arr);
    cout << Palindrome_In_LL(head) << endl;
    Print(head);
}