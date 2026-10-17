#include<bits/stdc++.h>
using namespace std;
vector<int> Next_Greater_Element(const vector<int>& arr, int n){
    stack<int> st;
    vector<int> new_arr(n);
    for(int i = n-1;i>=0;i--){
        while(!st.empty() && arr[i] >= st.top()) st.pop();
        if(st.empty()) new_arr[i] = -1;
        else new_arr[i] = st.top();
        st.push(arr[i]);
    }
    return new_arr;
}
void Print(const vector<int>& arr){
    cout << "New Array: ";
    for(int i = 0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
}
int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cout << "Element " << i+1 << ": ";
        cin >> arr[i];
    }
    vector<int> nge = Next_Greater_Element(arr,n);
    Print(nge);
}