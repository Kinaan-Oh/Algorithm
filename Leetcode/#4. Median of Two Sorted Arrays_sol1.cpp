// Merge Sort, Time Complexity: O(m+n), Space Complexity: O(m+n) (m: nums1.size, n: nums2.size)
// Merge Sort의 Merge 로직을 활용하여 정렬된 두 배열을 merge하는 방법 선택.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArray = merge(nums1, nums2);
        int n = mergedArray.size();
        if(n%2 == 0) {
            return (double)(mergedArray[n/2-1] + mergedArray[n/2])/2;
        }
        return mergedArray[n/2];
    }
    
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int idx1 = 0;
        int idx2 = 0;
        
        while(idx1<nums1.size() && idx2<nums2.size()) {
            if(nums1[idx1]<=nums2[idx2]) {
                result.push_back(nums1[idx1++]);
            } else if(nums1[idx1]>nums2[idx2]) {
                result.push_back(nums2[idx2++]);
            }
        }
        
        while(idx1<nums1.size()) {
            result.push_back(nums1[idx1++]);
        }
        
        while(idx2<nums2.size()) {
            result.push_back(nums2[idx2++]);
        }
        return result;
    }
};
