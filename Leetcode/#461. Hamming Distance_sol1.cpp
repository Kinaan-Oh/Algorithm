// 출제의도: "비트연산", Time Complexity: O(1), Space Complexity: O(1).
// xor, and, shift 연산자를 이용함.

class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0;
        x ^= y;
        while(x) {
            if(x&1)    dist++;
            x >>= 1;
        }
        return dist;
    }
};
