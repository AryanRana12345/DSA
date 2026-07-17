#include <vector>
#include <iostream>
using namespace std;
// [2, -3, 4, -2, 0, -5, -6]
int Maximum_Product_Subarray_In_Array(int n,vector<int>& arr){
    int left = 0;
    int right = n-1;
    int max_product = 0;
    int lproduct,rproduct = 1;
    for(int i=0;i<n;i++){
        lproduct = lproduct * arr[i];
        rproduct = rproduct * arr[n-i-1];
        max_product = max(max_product,max(lproduct,rproduct));
        if(lproduct == 0) lproduct = 1;
        if(rproduct == 0) rproduct = 1;
    }
    return max_product;
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
    cout << "Output: " << Maximum_Product_Subarray_In_Array(n,arr);
}