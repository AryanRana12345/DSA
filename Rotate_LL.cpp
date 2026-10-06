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
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;
    for(int i = 1;i<arr.size();i++){
        ListNode* y = new ListNode(arr[i]);
        mover -> next = y;
        mover = mover->next;
    }
    return head;
}
// 1 -> 2 -> 3 -> 4 -> 5, k = 2
ListNode* rotate(ListNode* head, int k){
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* temp = head;
    int cnt = 1;
    while(temp->next != nullptr){
        cnt++;
        temp = temp->next;
    }
    int fin_rot = k % cnt;
    if(fin_rot==0) return head;
    temp->next = head;
    ListNode* new_tail = head;
    for(int i = 1;i < cnt - fin_rot;i++){
        new_tail = new_tail->next;
    }
    ListNode* new_head = new_tail->next;
    new_tail->next = nullptr;
    return new_head;
}
void Print(ListNode* new_head){
    ListNode* temp = new_head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    ListNode* head = Converter(arr);
    int k = 9;
    ListNode* new_head = rotate(head,k);
    Print(new_head);
}