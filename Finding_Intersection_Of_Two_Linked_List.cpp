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
// 1 3 1 
//       2 4
//     3
ListNode* Finding_Intersection_Of_Two_Linked_List(ListNode* head1, ListNode* head2){
    if(head1 == nullptr || head2 == nullptr){
        return nullptr;
    }
    ListNode* temp1 = head1;
    ListNode* temp2 = head2;
    if(temp1 == temp2) return temp1;
    while(temp1 != nullptr || temp2 != nullptr){
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1 == temp2) return temp1;
        if(temp1 == nullptr) temp1 = head2;
        if(temp2 == nullptr) temp2 = head1;
    }
    return nullptr;
}
void Print(ListNode* head){
    ListNode* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main(){
    vector<int> arr1 = {1,3,1,2,4};
    ListNode* head1 = Array_To_Vector(arr1);
    ListNode* head2 = new ListNode(3);
    head2->next = head1->next->next->next;
    ListNode* new_head = Finding_Intersection_Of_Two_Linked_List(head1,head2);
    Print(new_head);
}