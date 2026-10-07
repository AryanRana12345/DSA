#include<bits/stdc++.h>
using namespace std;
class MyStack{
    public:
        int top = -1;
        int st[10];
        void push(int x){
            if(top == 9){
                cout << "Stack is full." << endl;
            }
            else{
                top++;
                st[top] = x;
            }
        }
        int pop(){
            if(top == -1){
                cout << "Stack is already empty." << endl;
                return -1;
            } 
            else{
                int pop_el = st[top];
                top--;
                return pop_el;
            }
        }
        int peek(){
            return st[top];
        }
        int getsize(){
            return top+1;
        }
};
int main(){
    MyStack st;
    st.push(2);
    st.push(5);
    cout << st.getsize() << endl;
    cout << st.pop() << endl;
    cout << st.getsize() << endl;
    cout << st.peek();
    return 0;
}