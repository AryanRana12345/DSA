#include <vector>
#include <iostream>
#include <climits>
using namespace std;
int Minimum_In_Rotated_Sorted_Array(int low,int high, vector<int>& arr){
    int mini = INT_MAX;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[low] <= arr[mid]){
            mini = min(mini,arr[low]);
            low = mid+1;
        }
        else{
            mini = min(mini,arr[mid]);
            high = mid-1;
        }
    }
    return mini;
}
int main(){
    int n;
    cout << "Number of elements: ";
    cin >> n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cout << "Element " << i+1 << ": ";
        cin >> temp;
        arr.push_back(temp);
    }
    int low = 0;
    int high = n-1;
    cout << "Output: " << Minimum_In_Rotated_Sorted_Array(low,high,arr);
}