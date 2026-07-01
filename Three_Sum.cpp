#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> Three_Sum(int n, vector<int> arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>> temp;
    for(int i=0;i<n;i++){
        if(i > 0 && arr[i-1] == arr[i]){
            continue;
        }
        int j = i+1;
        int k = n-1;
        while(j<k){
            if (arr[i] + arr[j] + arr[k] == 0){
                temp.push_back({arr[i],arr[j],arr[k]});
                while(arr[j] == arr[j+1] && j<k){
                    j++;
                }
                j++;
                while(arr[k-1] == arr[k] && j<k){
                    k--;
                }
                k--;
            }
            else if(arr[i] + arr[j] + arr[k] > 0){
                while(arr[k-1] == arr[k] && j<k){
                    k--;
                }
                k--;
            }
            else{
                while(arr[j] == arr[j+1] && j<k){
                    j++;
                }
                j++;
            }
        }
    }
    return temp;
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
    vector<vector<int>> result = Three_Sum(NumberOfElement,arr);
    for(const auto& row : result){
        for(int val:row){
            cout << val << " ";
        }
        cout << endl;
    }
}