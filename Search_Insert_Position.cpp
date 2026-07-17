#include <vector>
#include <iostream>
using namespace std;
int Search_Insert_Position(int low,int high,vector<int>& arr,int target){
    return lower_bound(arr.begin(),arr.end(),target) - arr.begin();
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
    cout << "Output: " << Search_Insert_Position(low,high,arr,Target)+1;
}