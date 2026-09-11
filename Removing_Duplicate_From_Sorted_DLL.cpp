#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
        int data;
        ListNode* next;
        ListNode* prev;
        ListNode(int data1, ListNode* next1=nullptr, ListNode* prev1=nullptr){
            data = data1;
            next = next1;
            prev = prev1;
        }
};
ListNode* Array_To_List(vector<int> arr1){
    ListNode* head = new ListNode(arr1[0]);
    ListNode* prev1 = head;
    for(int i = 1;i<arr1.size();i++){
        ListNode* el = new ListNode(arr1[i]);
        el->prev = prev1;
        prev1->next = el;
        prev1 = el;
    }
    return head;
}
ListNode* Removing_Duplicate_From_Sorted_DLL(ListNode* head){
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* temp = head->next;
    ListNode* prev1 = head;
    while(temp != nullptr){
        if(temp->data == prev1->data){
            while(temp != nullptr && temp->data == prev1->data){
                ListNode* del_node = temp;
                temp = temp->next;
                delete del_node;
            }
            if(temp == nullptr){
                prev1->next = nullptr;
                return head;
            }
            temp->prev = prev1;
            prev1->next = temp;
            prev1 = temp;
            temp = temp->next;
        }
        else{
            prev1 = temp;
            temp = temp->next;
        }
    }
    return head;
}
void Print(ListNode* head){
    ListNode* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    vector<int> arr1 = {1,1};
    ListNode* head = Array_To_List(arr1);
    ListNode* new_head = Removing_Duplicate_From_Sorted_DLL(head);
    Print(new_head);
}