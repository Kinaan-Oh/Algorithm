// Binary Search, Time Complexity: O(lgn), Space Complexity: O(1).
// 논리: sum of coins가 최초로 n이하인 stair를 binary search

class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1;
        int right = n;
        
        while(left<=right) {
            long long mid = left + (right-left)/2;
            
            if(mid*(mid+1)/2<=n) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return right;
    }
};
