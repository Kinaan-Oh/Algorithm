// "Brian Kernighan 알고리즘", Time Complexity: O(1), Space Complexity: O(1).
// n&(n-1)은 n의 가장 오른쪽 1을 제거하는 효과.

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n) {
            ans++;
            n &= (n-1);
        }
        return ans;
    }
};
