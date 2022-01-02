// 출제의도: "Binary Search", Time Complexity: O(lgn), Space Complexity: O(1).
// 입력으로 정렬된 수열이 주어진 것이 힌트.
// 탐색 범위 [left,right]를 절반씩 좁혀나가면서 찾음. 문제 크기가 절반씩 줄어들기 때문에 Time Complexity는 O(lgn).

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        if(nums.size()==1 && nums[0]==target)   return 0;
        
        while(left<=right) {
            int mid = (left+right)/2;
            if(nums[mid]<target)    left = mid+1;
            else if(nums[mid]>target)   right = mid-1;
            else    return mid;
        }
        return -1;
    }
};
