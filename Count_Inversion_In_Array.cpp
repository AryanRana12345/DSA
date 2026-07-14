#include<iostream>
#include<vector>
using namespace std;
int Merge(int low, int mid, int high, vector<int>& arr){
    int count = 0;
    int left = low;
    int right = mid+1;
    vector<int> temp;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
            count += (mid-left+1);
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low;i<=high;i++){
        arr[i] = temp[i-low];
    }
    return count;
}
int Count_Inversion_In_Array(int low, int high, vector<int>& arr){
    int count = 0;
    if(low >= high) return count;
    int mid = (low+high)/2;
    count += Count_Inversion_In_Array(low,mid,arr);
    count += Count_Inversion_In_Array(mid+1,high,arr);
    count += Merge(low,mid,high,arr);
    return count;
}
int main(){
    int NumberOfElements;
    cout << "Number of elements: ";
    cin >> NumberOfElements;
    vector<int> arr;
    for(int i=0;i<NumberOfElements;i++){
        cout << "Element " << i+1 << ": ";
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int low = 0;
    int high = NumberOfElements - 1;
    cout << Count_Inversion_In_Array(low,high,arr);
}