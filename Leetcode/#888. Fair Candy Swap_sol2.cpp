// Sort/Binary Search, Time Complexity: O((m+n)lgn), Space Complexity: O() (m: aliceSizes.size, n: bobSizes.size)
// sol1보다 효율성은 떨어지지만, 학습차원에서 구현.

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int>  answer;
        int sumA = 0;
        int sumB = 0;
        
        for(auto aliceSize: aliceSizes)    sumA += aliceSize;
        for(auto bobSize: bobSizes)    sumB += bobSize;
        
        sort(bobSizes.begin(), bobSizes.end());
            
        for(auto sliceSize: aliceSizes) {
            int left = 0;
            int right = bobSizes.size()-1;
            int target = sliceSize + (sumB-sumA)/2;
            
            while(left<=right) {
                long long mid = left + (right-left)/2;

                if(bobSizes[mid]==target) {
                    return {sliceSize, bobSizes[mid]};
                } else if(bobSizes[mid]<target) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }
        return {};
    }
};
