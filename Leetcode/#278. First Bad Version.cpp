// Binary Search, Time Complexity: O(lgn), Space Complexity: O(1)
// 첫 시도에 mid = (left+right)/2로 overflow 발생. left + (right-left)/2로 변경하여 해당 문제 회피.

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        
        while(left<right) {
            int mid = left + (right-left)/2;
            
            if(isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return right;
    }
};
