class Solution {
public:
    int solve(vector<int>& arr , int low , int high){
        if(low == high){
            return low;
        }
        int mid = low + (high - low) / 2;
        if(arr[mid+1] > arr[mid]){
            return solve(arr, mid+1, high);
        } else {
            return solve(arr, low, mid);
        }
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        return solve(arr,0,arr.size()-1);
    }
};