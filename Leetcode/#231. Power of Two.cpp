// Math/Binary System, Time Complexity: O(1), Space Complexity: O(1)
// 논리: 0을 제외한 임의의 정수가 power of two가 되기 위해서는 left most bit를 제외한 모든 bit이 0이어야만 한다.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)    return false;
        
        while(n%2==0) {
            n/=2;
        }
        return n==1;
    }
};
