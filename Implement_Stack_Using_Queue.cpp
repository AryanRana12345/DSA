#include<bits/stdc++.h>
using namespace std;
class MyStack{
    public:
        queue<int> que;
        int size = 0;
        void push(int x){
            size++;
            int i = size;
            que.push(x);
            while(i > 1){
                que.push(que.front());
                que.pop();
                i--;
            }
        }
        void pop(){
            if(!que.empty()){
                que.pop();
                size--;
            } 
        }
        int top(){
            if(que.empty()) return -1;
            return que.front();
        }
        int getsize(){
            return size;
        }
};
int main(){
    MyStack st;
    st.pop();
    cout << st.top() << endl;
    cout << st.getsize() << endl;
    st.push(5);
    st.push(3);
    st.push(1);
    cout << st.getsize() << endl;
    st.pop();
    st.pop();
    cout << st.getsize() << endl;
    return 0;
}