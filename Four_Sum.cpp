#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> Four_Sum(int n, vector<int> arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>> temp;
    for(int i=0;i<n-3;i++){
        if(i > 0 && arr[i-1] == arr[i]){
            continue;
        }
        for(int j=i+1;j<n-2;j++){
            if(j > i+1 && arr[j-1] == arr[j]){
                continue;
            }
            int k = j+1;
            int l = n-1;
            while(k<l){
                if (arr[i] + arr[j] + arr[k] + arr[l] == 0){
                    temp.push_back({arr[i],arr[j],arr[k],arr[l]});
                    while(arr[k] == arr[k+1] && k<l){
                        k++;
                    }
                    k++;
                    while(arr[l-1] == arr[l] && k<l){
                        l--;
                    }
                    l--;
                }
                else if(arr[i] + arr[j] + arr[k] + arr[l] > 0){
                    while(arr[l-1] == arr[l] && k < l){
                        l--;
                    }
                    l--;
                }
                else{
                    while(arr[k] == arr[k+1] && k<l){
                        k++;
                    }
                    k++;
                }
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
    vector<vector<int>> result = Four_Sum(NumberOfElement,arr);
    for(const auto& row : result){
        for(int val:row){
            cout << val << " ";
        }
        cout << endl;
    }
}