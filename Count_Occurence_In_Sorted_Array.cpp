#include <vector>
#include <iostream>
using namespace std;
int First_Occurence(int low,int high, vector<int>& arr,int Target){
    int index = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] >= Target){
            index = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return index;
}
int Last_Occurence(int low,int high, vector<int>& arr,int Target){
    int index = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] < Target){
            low = mid+1;
        }
        else if(arr[mid]==Target){
            index = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return index;
}
int First_And_Last_Occurence(int low,int high, vector<int>& arr,int Target){
    int first = First_Occurence(low,high,arr,Target);
    int last = Last_Occurence(low,high,arr,Target);
    if(first == -1 && last == -1) return 0;
    return last - first + 1;
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
    cout << First_And_Last_Occurence(low,high,arr,Target);
}