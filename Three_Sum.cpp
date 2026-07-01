#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> Three_Sum(int n, vector<int> arr){
    sort(arr.begin(),arr.end());
}
int main(){
    int NumberOfElement;
    cout << "Number of elements you want in the array";
    cin >> NumberOfElement;
    vector<int> arr(NumberOfElement);
    for(int i=0;i<NumberOfElement;i++){
        int Element;
        cout << "Element " << (i+1) << " : ";
        cin >> Element;
        arr[i] = Element;
    }
    Three_Sum(NumberOfElement,arr);
    for(int i=0;i<NumberOfElement;i++){
        cout << arr[i] << endl;
    }
    return 0;
}