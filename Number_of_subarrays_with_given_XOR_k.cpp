#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int Number_of_subarrays_with_given_XOR_k(int n, int Target, vector<int> arr){
    unordered_map<int,int> temp;
    temp[0] = 1;
    int xorr = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        xorr = xorr ^ arr[i];
        int finding = xorr ^ Target;
        if(temp.find(finding) != temp.end()){
            count = count + temp[finding];
        }
        temp[xorr]++;
    }
    return count;
}

int main(){
    int NumberOfElement;
    int Target;
    cout << "Number of elements you want in the array ";
    cin >> NumberOfElement;
    cout << "Target: ";
    cin >> Target;
    vector<int> arr(NumberOfElement);
    for(int i=0;i<NumberOfElement;i++){
        int Element;
        cout << "Element " << (i+1) << " : ";
        cin >> Element;
        arr[i] = Element;
    }
    cout << Number_of_subarrays_with_given_XOR_k(NumberOfElement,Target,arr);
}