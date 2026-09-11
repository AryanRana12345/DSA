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
ListNode* Reverse_LL_Recursive(ListNode* temp){
    if(temp == nullptr || temp->next == nullptr){
        return temp;
    }
    ListNode* el = Reverse_LL_Recursive(temp->next);
    temp->next->next = temp;
    temp->next = NULL;
    return el;
}
void Print(ListNode* head){
    ListNode* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main(){
    vector<int> arr = {1,2,1,3};
    ListNode* head = Array_To_Vector(arr);
    ListNode* new_head = Reverse_LL_Recursive(head);
    Print(new_head);
}