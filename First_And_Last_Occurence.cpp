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
pair<int,int> First_And_Last_Occurence(int low,int high, vector<int>& arr,int Target){
    int first = First_Occurence(low,high,arr,Target);
    int last = Last_Occurence(low,high,arr,Target);
    return {first,last};
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
    pair<int,int> ans = First_And_Last_Occurence(low,high,arr,Target);
    cout << "First Occurence: " << ans.first+1 << endl;
    cout << "Second Occurence: " << ans.second+1;
}