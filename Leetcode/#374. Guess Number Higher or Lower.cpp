// Binary Search, Time Complexity: O(lgn), Space Complexity: O(1)

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        
        while(left<=right) {
            long long mid = left + (right-left)/2;
            
            if(guess(mid)==1) {
                left = mid+1;
            } else if(guess(mid)==-1) {
                right = mid-1;
            } else {
                right = mid;
                break;
            }
        }
        return right;
    }
};
