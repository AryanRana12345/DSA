//{6, -2, 2, -8, 1, 7, 4, -10} 
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int Largest_Subarray_with_Sum_Zero(int n, vector<int> arr){
    unordered_map<int,int> hash_map;
    int length = 0;
    hash_map[0] = -1;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum + arr[i];
        if (hash_map.find(sum) != hash_map.end()){
            length = max(length,i - hash_map[sum]);
        }
        else{
            hash_map[sum] = i;
        }
    }
    return length;
}
int main(){
    int NumberOfElement;
    cout << "Number of elements you want in the array ";
    cin >> NumberOfElement;
    vector<int> arr(NumberOfElement);
    for(int i=0;i<NumberOfElement;i++){
        int Element;
        cout << "Element " << (i+1) << " : ";
        cin >> Element;
        arr[i] = Element;
    }
    cout << Largest_Subarray_with_Sum_Zero(NumberOfElement,arr);
}