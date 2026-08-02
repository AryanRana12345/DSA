#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int Calculation(vector<int>& arr,int t,int mid){
    int current_cow = 0;
    t--;
    for(int i=1;i<arr.size();i++){
        if(arr[i]-arr[current_cow]>=mid){
            t--;
            current_cow = i;
        }
    }
    if(t<=0) return 1;
    else return 0; 
}
int Aggresive_Cow_Allocation(vector<int>& arr,int t){
    if(t>arr.size()) return -1;
    sort(arr.begin(),arr.end());
    int low = 1;
    int high = arr[arr.size()-1] - arr[0] + 1;
    while(low<=high){
        int mid = low + (high-low)/2;
        int result = Calculation(arr,t,mid);
        if(result == 1) low = mid+1;
        else high = mid-1;
    }
    return high;
}
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr;
    for(int i=1;i<=n;i++){
        int temp;
        cout << "Enter " << i << " element: ";
        cin >> temp;
        arr.push_back(temp);
    }
    int t;
    cout << "Target: ";
    cin >> t;
    cout << "Output: " << Aggresive_Cow_Allocation(arr,t);
}