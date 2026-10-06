#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode* child;
        ListNode(int data1, ListNode* next1 = nullptr, ListNode* child1 = nullptr){
            val = data1;
            next = next1;
            child = child1;
        }
};
ListNode* Flattening_Of_LL(ListNode* head){
    ListNode* temp = head;
    ListNode* temp2 = temp->next;
    ListNode* psuedo = new ListNode(-1);
    ListNode* recent = psuedo;
    while(temp2 != nullptr){
        ListNode* temp3 = temp2->next;
        temp->next = nullptr;
        temp2->next = nullptr;
        while(temp != nullptr && temp2 != nullptr){
            if(temp->val <= temp2->val){
                recent->child = temp;
                recent = temp;
                temp = temp->child;
            }
            else{
                recent->child = temp2;
                recent = temp2;
                temp2 = temp2->child;
            }
        }
        if(temp != nullptr) recent->child = temp;
        else recent->child = temp2;
        temp = psuedo->child;
        temp2 = temp3;
        recent = psuedo;
    }
    return psuedo->child;
}
void Print(ListNode* nh){
    ListNode* temp = nh;
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->child;
    }
}
int main() {
    ListNode* head3 = new ListNode(3);
    ListNode* head2 = new ListNode(2);
    ListNode* head1 = new ListNode(1);
    ListNode* head4 = new ListNode(4);
    ListNode* head5 = new ListNode(5);
    head3->next = head2;
    head2->next = head1;
    head1->next = head4;
    head4->next = head5;
    head2->child = new ListNode(10);
    head1->child = new ListNode(7);
    head1->child->child = new ListNode(11);
    head1->child->child->child = new ListNode(12);
    head4->child = new ListNode(9);
    head5->child = new ListNode(6);
    head5->child->child = new ListNode(8);
    ListNode* head = head3;
    ListNode* new_head = Flattening_Of_LL(head); 
    Print(new_head);
    return 0;
}
