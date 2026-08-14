#include<iostream>
#include<vector>
#include <climits>
using namespace std;
double Kth_Element_Of_Two_Sorted_Array(vector<int>& nums1,vector<int>& nums2, int n1, int n2, int k){
    if(n1 > n2) return Kth_Element_Of_Two_Sorted_Array(nums2,nums1,n2,n1,k);
    int mid1 = k;
    int n = n1+n2;
    int low = max(0,k-n2);
    int high = min(n1,k);
    while(low<=high){
        int mid = low + (high-low)/2;
        int mid2 = mid1 - mid;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;
        if(mid-1 >=0) l1 = nums1[mid-1];
        if(mid < n1) r1 = nums1[mid];
        if(mid2-1 >=0) l2 = nums2[mid2-1];
        if(mid2 < n2) r2 = nums2[mid2];
        if(l1 > r2) high = mid-1;
        else if(l2>r1) low = mid+1;
        else{
            return max(l1,l2);
        }
    }
    return 0;
}
int main(){
    int n1;
    cout << "Size of First Array: ";
    cin >> n1;
    vector<int> nums1;
    for(int i = 1;i <= n1;i++){
        int temp;
        cout << "Element " << i << ": ";
        cin >> temp;
        nums1.push_back(temp);
    }
    int n2;
    cout << "Size of Second Array: ";
    cin >> n2;
    vector<int> nums2;
    for(int i = 1;i <= n2;i++){
        int temp;
        cout << "Element " << i << ": ";
        cin >> temp;
        nums2.push_back(temp);
    }
    int k;
    cout << "K: ";
    cin >> k;
    cout << "Output: " << Kth_Element_Of_Two_Sorted_Array(nums1,nums2,n1,n2,k);
}