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
int Length_Of_Loop_In_LL(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            int cnt = 1;
            slow = slow->next;
            while(slow != fast){
                slow = slow->next;
                cnt++; 
            }
            return cnt;
        }
    }
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
    cout << Length_Of_Loop_In_LL(head);
}