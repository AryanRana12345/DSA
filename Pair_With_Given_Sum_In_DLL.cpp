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
vector<pair<int,int>> Pair_With_Given_Sum_In_DLL(ListNode* head, int target){
    ListNode* start = head;
    ListNode* end = head;
    vector<pair<int,int>> sol;
    while(end->next != nullptr){
        end = end->next;
    }
    while(start->data <= end->data && start != end){
        int sum = start->data + end->data;
        if(sum == target){
            sol.push_back({start->data,end->data});
            while(start->next->data == start->data){
                start = start->next;
            }
            start = start->next;
            while(end->prev->data == end->data){
                end = end->prev;
            }
            end = end->prev;
        }
        else if(sum < target){
            while(start->next->data == start->data){
                start = start->next;
            }
            start = start->next;
        }
        else{
            while(end->prev->data == end->data){
                end = end->prev;
            }
            end = end->prev;
        }
    }
    return sol;
}
int main(){
    vector<int> arr1 = {1,2,3,4,5,6,7,8,9};
    ListNode* head = Array_To_List(arr1);
    int target;
    cout << "Target: ";
    cin >> target;
    vector<pair<int,int>> sol = Pair_With_Given_Sum_In_DLL(head,target);
    for(int i = 0;i<sol.size();i++){
        cout << "(" << sol[i].first << "," << sol[i].second << ")" << endl;
    }
}