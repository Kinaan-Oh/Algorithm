// 출제의도: "Binary Search", Time Complexity: O(lgn), Space Complexity: O(1).
// Coding Interview에서 풀어보았던 문제. 정렬된 수열이 회전된 특수한 상황에서 이분 탐색으로 최솟값 혹은 최댓값을 탐색해 낼 수 있음. 만일, 다른 상황(부분적으로 정렬상태가 유지되지않고 임의로 섞여있는)이라면
// 사용할 수 없음.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        if(nums.size()==1 || nums[left]<nums[right])   return nums[0];
        
        while(right-left>1) {
            int mid = (left+right)/2;
            if(nums[mid]<nums[right]) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return nums[right];
    }
};
