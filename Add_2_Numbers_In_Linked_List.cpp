#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
        int data;
        ListNode* next;
        ListNode(int data1,ListNode* next1=nullptr){
            data = data1;
            next = next1;
        }
};
pair<ListNode*, ListNode*> Array_To_List(vector<int>& arr1, vector<int>& arr2){
    ListNode* head1 = new ListNode(arr1[0]);
    ListNode* head2 = new ListNode(arr2[0]);
    ListNode* temp1 = head1;
    ListNode* temp2 = head2;
    for(int i=1;i<arr1.size();i++){
        ListNode* temp3 = new ListNode(arr1[i]);
        temp1->next = temp3;
        temp1=temp1->next;
    }
    for(int i=1;i<arr2.size();i++){
        ListNode* temp4 = new ListNode(arr2[i]);
        temp2->next = temp4;
        temp2 = temp2->next;
    }
    return {head1,head2};
}
ListNode* Suming(ListNode* head1, ListNode* head2){
    ListNode* temp1 = head1;
    ListNode* temp2 = head2;
    if(temp1 == nullptr && temp2 == nullptr) return nullptr;
    if(temp1 == nullptr && temp2 != nullptr) return temp2;
    if(temp1 != nullptr && temp2 == nullptr) return temp1;
    int carry = 0;
    int sum = temp1->data + temp2->data + carry;
    int digit = sum%10;
    carry = sum/10;
    ListNode* temp5 = new ListNode(sum);
    temp1=temp1->next;
    temp2 = temp2->next;
    ListNode* new_head = temp5;
    while(temp1 != nullptr && temp2 != nullptr){
        int temp3 = temp1->data + temp2->data + carry;
        sum = temp3%10;
        ListNode* temp6 = new ListNode(sum);
        temp5->next = temp6;
        temp5 = temp5->next;
        carry = temp3/10;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    while(temp1 != nullptr){
        int sum = temp1->data + carry;
        ListNode* temp6 = new ListNode(sum);
        temp5->next = temp6;
        temp5 = temp5->next;
        carry = sum/10;
        temp1 = temp1->next;
    }
    while(temp2 != nullptr){
        int sum = temp2->data + carry;
        ListNode* temp6 = new ListNode(sum);
        temp5->next = temp6;
        temp5 = temp5->next;
        carry = sum/10;
        temp2 = temp2->next;
    }
    if(carry != 0){
        ListNode* temp6 = new ListNode(carry);
        temp5->next = temp6;
    }
    return new_head;
}
void Print(ListNode* head){
    ListNode* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main(){
    vector<int>arr1 = {3,8,7,8};
    vector<int>arr2 = {5,2,8,3};
    pair<ListNode* , ListNode*> heads = Array_To_List(arr1,arr2);
    ListNode* head = Suming(heads.first,heads.second);
    Print(head);
}