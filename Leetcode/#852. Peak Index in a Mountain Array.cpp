// Binary Search, Time Complexity: O(lgn), Space Complexity: O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size()-1;
        
        while(left<=right) {
            long long mid = left + (right-left)/2;
            
            if(mid==0 || arr[mid]>arr[mid-1]) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return right;
    }
};
