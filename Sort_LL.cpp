#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int val1, ListNode* next1 = nullptr){
            val = val1;
            next = next1;
        }
};
ListNode* Converter(vector<int>& arr){
    if(arr.size() == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;
    for(int i = 1;i<arr.size();i++){
        ListNode* y = new ListNode(arr[i]);
        mover -> next = y;
        mover = mover->next;
    }
    return head;
}
// head -> 5 -> 6 -> 1 -> 2 -> 1
// head -> 5 -> 6 -> 1 -> 2
ListNode* merge_sort(ListNode* head, ListNode* next_head);
ListNode* sorting(ListNode* head){
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* next_head = slow->next;
    slow->next = nullptr;
    ListNode* head1 = sorting(head);
    ListNode* next_head1 = sorting(next_head);
    return merge_sort(head1,next_head1);
}
ListNode* merge_sort(ListNode* head, ListNode* next_head){
    ListNode* psuedo = new ListNode(-1);
    ListNode* recent = psuedo;
    ListNode* temp1 = head;
    ListNode* temp2 = next_head;
    while(temp1 != nullptr && temp2 != nullptr){
        if(temp1->val <= temp2->val){
            recent->next = temp1;
            recent = temp1;
            temp1 = temp1->next;
        }
        else{
            recent->next = temp2;
            recent = temp2;
            temp2 = temp2->next;
        }
    }
    if(temp1 != nullptr) recent->next = temp1;
    else recent->next = temp2;
    ListNode* merged_head = psuedo->next;
    delete psuedo;
    return merged_head;
}
void Print(ListNode* new_head){
    ListNode* temp = new_head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
}
int main(){
    vector<int> arr = {2,1,7,9,8};
    ListNode* head = Converter(arr);
    ListNode* new_head = sorting(head);
    Print(new_head);
}