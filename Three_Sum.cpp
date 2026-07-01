#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> Three_Sum(int n, vector<int> arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>> temp;
    for(int i=0;i<n;i++){
        int j = i+1;
        int k = n-1;
        while(j<k){
            if (arr[i] + arr[j] + arr[k] == 0){
                sort();
                temp.push_back({arr[i],arr[j],arr[k]});

            }
        }
    }
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