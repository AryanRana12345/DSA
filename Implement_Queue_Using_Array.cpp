#include<bits/stdc++.h>
using namespace std;
class MyQueue{
    public:
        int start = -1;
        int end = -1;
        int size = 0;
        int capacity = 10;
        int que[10];
        void push(int x){
            if(size == 10) cout << "The queue is full." << endl;
            else{
                if(size == 0){
                    start = 0;
                }
                end = (end+1)%capacity;
                que[end] = x;
                size++;
            }
        }
        int pop(){
            if(size == 0){
                cout << "The queue is empty." << endl;
                return -1;
            }
            int temp = que[start];
            size--;
            if(size == 0){
                start = -1;
                end = -1;
            }
            else{
                start = (start+1)%capacity;
            }
            return temp;
        }
        int peek(){
            if(size == 0) return -1;
            return que[start];
        }
        int getsize(){
            return size;
        }
};
int main(){
    MyQueue st;
    st.push(2);
    st.push(5);
    cout << st.getsize() << endl;
    cout << st.pop() << endl;
    cout << st.getsize() << endl;
    cout << st.peek() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.peek() << endl;
    st.push(3);
    cout << st.peek() << endl;
    return 0;
}