// "Bitmask(XOR)", Time Complexity: O(n), Space Complexity: O(1).
// XOR 연산자 : 1) 교환법칙: a xor b xor c == a xor c xor b, 2) a xor 0 == a, 3) a xor a == 0.
// (a xor b) xor a == (a xor a) xor b = 0 xor b = b

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int memo=0;
        for(int i=0;i<nums.size();i++) {
            memo ^= nums[i];
        }
        return memo;
    }
};
