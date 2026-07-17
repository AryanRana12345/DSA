#include <vector>
#include <iostream>
using namespace std;
int Lower_Bound(int low,int high, vector<int>& arr,int Target){
    int index = arr.size();
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == Target){
            return mid;
        }else if(arr[mid] < Target){
            low = mid+1;
        }else{
            index = mid;
            high = mid-1;
        }
    }
    return index;
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
    cout << "Output: " << Lower_Bound(low,high,arr,Target)+1;
}