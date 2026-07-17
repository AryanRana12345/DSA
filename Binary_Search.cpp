#include <vector>
#include <iostream>
using namespace std;
int Binary_Search(int low,int high,vector<int> arr,int Target){
    if(low>high) return -1;
    int mid = (low + high)/2;
    if(Target < arr[mid]){
        high = mid-1;
        return Binary_Search(low,high,arr,Target);
    }
    else if(arr[mid] < Target){
        low = mid+1;
        return Binary_Search(low,high,arr,Target);
    }
    else{
        return mid;
    }
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
    cout << "Output: " << Binary_Search(low,high,arr,Target)+1;
}