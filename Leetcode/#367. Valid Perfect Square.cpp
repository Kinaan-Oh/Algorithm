// Binary Search, Time Complexity: O(lgn), Space Complexity: O(1)

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;
        
        while(left<=right) {
            long long mid = left + (right-left)/2;
            
            if(mid*mid<num) {
                left = mid+1;
            } else if(mid*mid>num) {
                right = mid-1;
            } else {
                return true;
            }
        }
        return false;
    }
};
