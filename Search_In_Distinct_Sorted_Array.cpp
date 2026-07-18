#include <vector>
#include <iostream>
using namespace std;
int Search_In_Distinct_Sorted_Array(int low,int high, vector<int>& arr,int Target){
    while(low<=high){
        int mid = (low + high)/2;
        if(arr[mid] == Target){
            return mid;
        }
        else if(arr[mid] >= arr[low]){
            if(arr[mid] > Target && Target >= arr[low]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            if(arr[mid] < Target && Target <= arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
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
    int Target;
    cout << "Target Number: ";
    cin >> Target;
    int low = 0;
    int high = n-1;
    cout << "Output: " << Search_In_Distinct_Sorted_Array(low,high,arr,Target)+1;
}