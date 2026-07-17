#include <vector>
#include <iostream>
using namespace std;
long long Floor(int low,int high,vector<int>& arr,int Target){
    long long floor = 0;
    while(low<=high){
        long long mid = (low+high)/2;
        if(arr[mid] > Target){
            high = mid-1;
        }
        else if(arr[mid] < Target){
            floor = mid;
            low = mid+1;
        }
        else{
            return mid;
        }
    }
    return floor;
}
int Ceil(int low,int high,vector<int>& arr,int Target){
    int ceil = arr.size();
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] < Target){
            low = mid+1;
        }
        else if(arr[mid] > Target){
            ceil = mid;
            high = mid-1;
        }
        else{
            return mid;
        }
    }
    return ceil;
}
pair<int,int> Floor_And_Ceil_In_Sorted_Array(int low,int high,vector<int>& arr,int Target){
    int floor = Floor(low,high,arr,Target);
    int ceil = Ceil(low,high,arr,Target);
    return {floor,ceil};
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
    pair<int,int> ans= Floor_And_Ceil_In_Sorted_Array(low,high,arr,Target);
    cout << "Floor: " << ans.first+1 << endl;
    cout << "Ceil: " << ans.second+1;
}