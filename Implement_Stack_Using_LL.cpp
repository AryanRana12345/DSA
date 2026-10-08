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
class MyStack{
    public:
        ListNode* top = nullptr;
        int size = 0;
        void push(int x){
            ListNode* temp = new ListNode(x,top);
            top = temp;
            size++;
        }
        int pop(){
            if(top == nullptr) return -1;
            ListNode* temp = top;
            int value = top->val;
            top = top->next;
            delete temp;
            size--;
            return value;
        }
        int peek(){
            if(top == nullptr) return -1;
            return top->val;
        }
        int getsize(){
            return size;
        }
};
int main(){
    MyStack st;
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