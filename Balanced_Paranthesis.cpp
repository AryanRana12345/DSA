#include<bits/stdc++.h>
using namespace std;
bool Balanced_Paranthesis(string st){
    stack<char> sta;
    for(int i = 0;i<st.size();i++){
        if(st[i] == '{' || st[i] == '[' || st[i] == '('){
            sta.push(st[i]);
        }
        else if(st[i] == '}' || st[i] == ']' || st[i] == ')'){
            if(sta.size() == 0) return false;
            char lc = sta.top();
            if((st[i] == '}' && lc == '{') || (st[i] == ']' && lc == '[') || (st[i] == ')' && lc == '(')){
                sta.pop();
            }
            else{
                return false;
            }   
        }
    }
    if(sta.size() == 0) return true;
    return false;
}
int main(){
    string st;
    cout << "Enter Input: ";
    cin >> st;
    cout << Balanced_Paranthesis(st);
}