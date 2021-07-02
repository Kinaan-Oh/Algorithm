// "Brian Kernighan 알고리즘", Time Complexity: O(1), Space Complexity: O(1).
// sol1은 Int 자료형의 비트수만큼 반복이 필요한데, Brian ?kernighan 알고리즘은 비트내 1의 갯수만큼만 반복하면 된다.
// x&(x-1) 은 x의 가장 오른쪽 1을 제거하는 효과를 갖는다. 그 이유는 1을 빼면 가장 오른쪽 1을 받아내림해야 되기 때문이다.

class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0;
        x ^= y;
        while(x) {
            dist++;
            x &= (x-1);
        }
        return dist;
    }
};
