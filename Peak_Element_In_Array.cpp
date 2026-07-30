#include <vector>
#include <iostream>
using namespace std;
// 1 2 3 4 5 6 7 8 5 1
int Peak_Element_In_Array(int low,int high, vector<int>& arr){
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
            return mid;
        }
        else if(arr[mid] > arr[mid-1]){
            low=mid+1;
        }
        else{
            high=mid-1;
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
    cout << "Output: " << Peak_Element_In_Array(low,high,arr);
}