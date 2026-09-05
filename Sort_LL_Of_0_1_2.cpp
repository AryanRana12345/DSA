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
ListNode* sorting_LL(ListNode* head){
    if(head == nullptr) return nullptr;
    ListNode* temp = head;
    ListNode* head_0 = nullptr;
    ListNode* head_0_helper = nullptr;
    ListNode* head_1 = nullptr;
    ListNode* head_1_helper = nullptr;
    ListNode* head_2 = nullptr;
    ListNode* head_2_helper = nullptr;
    while(temp != nullptr){
        if(temp->data == 0){
            if(head_0 == nullptr){
                head_0 = temp;
                head_0_helper = temp;
            }
            else{
                head_0_helper->next = temp;
                head_0_helper = head_0_helper->next;
            }
            temp = temp->next;
        }
        else if(temp->data == 1){
            if(head_1 == nullptr){
                head_1 = temp;
                head_1_helper = temp;
            }
            else{
                head_1_helper->next = temp;
                head_1_helper=head_1_helper->next;
            }
            temp = temp->next;

        }
        else if(temp->data == 2){
            if(head_2 == nullptr){
                head_2 = temp;
                head_2_helper = temp;
            }
            else{
                head_2_helper->next = temp;
                head_2_helper = head_2_helper->next;
            }
            temp = temp->next;
        }
    }
    if(head_0_helper != nullptr && head_1 != nullptr) head_0_helper->next = head_1;
    if(head_1_helper != nullptr) head_1_helper->next = head_2;
    if(head_1_helper == nullptr and head_0_helper != nullptr) head_0_helper->next = head_2;
    if(head_2_helper != nullptr) head_2_helper->next = nullptr;
    if(head_0 != nullptr) return head_0;
    if(head_1 != nullptr) return head_1;
    return head_2;
}
void Print(ListNode* head){
    ListNode* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main(){
    vector<int> arr = {2,2,2,2,2};
    ListNode* head = Array_To_Vector(arr);
    ListNode* sorted_head = sorting_LL(head);
    Print(sorted_head);
}