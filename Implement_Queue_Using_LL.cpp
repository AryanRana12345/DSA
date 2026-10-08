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
class MyQueue{
    public:
        ListNode* psuedo = new ListNode(-1);
        ListNode* end = psuedo;
        int size = 0;
        void push(int x){
            ListNode* temp = new ListNode(x);
            end->next = temp;
            end = temp;
            size++;
        }
        int pop(){
            if(end == psuedo) return -1;
            int temp = psuedo->next->val;
            ListNode* temp2 = psuedo->next;
            psuedo->next = psuedo->next->next;
            delete temp2;
            size--;
            if(size == 0) end = psuedo;
            return temp;
        }
        int peek(){
            if(end == psuedo) return -1;
            return psuedo->next->val;
        }
        int getsize(){
            return size;
        }
};
int main(){
    MyQueue st;
    cout << st.pop() << endl;
    st.push(2);
    st.push(5);
    st.push(1);
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.peek() << endl;
    cout << st.getsize() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.peek() << endl;
    cout << st.getsize();
}