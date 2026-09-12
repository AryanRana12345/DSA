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
ListNode* Starting_Point_Of_Cycle_In_LL(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            fast = head;
            while(fast != slow){
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return nullptr;
}
void Print(ListNode* head){
    ListNode* temp = head;
    ListNode* temp2 = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != temp2);
}
int main(){
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *fourth = new ListNode(4);
    ListNode *fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third;
    ListNode* new_head = Starting_Point_Of_Cycle_In_LL(head);
    Print(new_head);
}