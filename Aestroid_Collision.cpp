#include<bits/stdc++.h>
using namespace std;
vector<int> Aestroid_Collision(vector<int> arr){
    int n = arr.size();
    stack<int> st;
    for(int i = 0;i<n;i++){
        while(!st.empty() && st.top() > 0 && arr[i] < 0 && abs(st.top()) < abs(arr[i])){
            st.pop();
        }
        if(!st.empty() && st.top() > 0 && arr[i] < 0 && abs(st.top()) == abs(arr[i])){
            st.pop();
            continue;
        }
        if(!st.empty() && st.top() > 0 && arr[i] < 0 && abs(st.top()) > abs(arr[i])) continue;
        st.push(arr[i]);
    }
    vector<int> new_arr(st.size());
    for(int i = new_arr.size()-1;i >= 0;i--){
        new_arr[i] = st.top();
        st.pop();
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
    vector<int> nge = Aestroid_Collision(arr);
    Print(nge);
}