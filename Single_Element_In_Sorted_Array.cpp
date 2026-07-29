#include <vector>
#include <iostream>
using namespace std;
int Single_Element_In_Sorted_Array(int low,int high, vector<int>& arr){
    if(arr.size() == 1){
        return arr[0];
    }
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]){
            return arr[mid];
        }
        if(((mid%2==0) && (arr[mid+1] == arr[mid])) || ((mid%2!=0) && (arr[mid-1] == arr[mid]))){
            low=mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
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
    cout << "Output: " << Single_Element_In_Sorted_Array(low,high,arr);
}