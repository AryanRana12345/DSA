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
// 1 2 3 4 5 6 7
ListNode* helper(ListNode*& temp, ListNode*& new_head, ListNode*& next_grp_connection, ListNode*& head, ListNode*& prev_grp_tail, int i, int k){
    if(i == 1){
        next_grp_connection = temp->next;
        if(new_head == head) new_head = temp;
        if(prev_grp_tail != nullptr){
            prev_grp_tail->next = temp;
        }
        return temp;
    }
    i--;
    ListNode* new_el = helper(temp->next,new_head,next_grp_connection,head,prev_grp_tail,i,k);
    temp->next->next = temp;
    temp->next = nullptr;
    return temp;
}
ListNode* Reverse_Node_In_K_Group_LL(ListNode* head, int k){
    ListNode* temp = head;
    ListNode* checker = head;
    ListNode* new_head = head;
    ListNode* next_grp_connection = nullptr;
    ListNode* prev_grp_tail = nullptr;
    while(checker != nullptr){
        for(int i = k;i>0;i--){
            if(checker != nullptr) checker = checker->next;
            else return new_head;
        }
        int i = k;
        temp = helper(temp,new_head,next_grp_connection,head,prev_grp_tail,i,k);
        temp->next = next_grp_connection;
        prev_grp_tail = temp;
        temp = temp->next;
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
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    ListNode* head = Array_To_Vector(arr);
    int k;
    cout << "Group Size: ";
    cin >> k;
    ListNode* new_head = Reverse_Node_In_K_Group_LL(head,k);
    Print(new_head);
}