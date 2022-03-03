// Binary Search, Time Complexity: O(lgx), Space Complexity: O(1)
// 논리: 제곱이 x이하인 최초의 수를 binary search

class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        
        while(left<=right) {
            long long mid = left + (right-left)/2;
            
            if(mid*mid<=x) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return right;
    }
};
