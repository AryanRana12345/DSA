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
ListNode* Delete_All_Occurence_Of_Key_In_DLL(ListNode* head, int key){
    ListNode* psuedo = new ListNode(-1);
    psuedo->next = head;
    head->prev = psuedo;
    ListNode* temp = head;
    while(temp!=nullptr){
        if(temp->data == key){
            ListNode* next_loop = temp->next;
            temp->prev->next = temp->next;
            if(temp->next != nullptr) temp->next->prev = temp->prev;
            temp->next = nullptr;
            temp->prev = nullptr;
            delete temp;
            temp = next_loop;
        }
        else temp = temp->next;
    }
    return psuedo->next;
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
    vector<int> arr1 = {1,2,3,4,5,3,7,3};
    ListNode* head = Array_To_List(arr1);
    int key;
    cout << "Key: ";
    cin >> key;
    ListNode* new_head = Delete_All_Occurence_Of_Key_In_DLL(head,key);
    Print(new_head);
}