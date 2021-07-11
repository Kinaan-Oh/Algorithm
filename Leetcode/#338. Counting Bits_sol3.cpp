// "DP", Time Complexity: O(n), Space Complexity: O(n).
// idea: 임의의 수 k에 대하여 k/2는 least significant bit를 제외한 왼쪽 비트들로 구성된 이진수(자리수는 1씩 낮아진다.)를, k%2는 least significant bit를 의미한다.

class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0)    return {0};
        vector<int> memo(n+1,0);
        memo[0] = 0, memo[1] = 1;
        
        for(int i=2;i<=n;i++) {
            memo[i] = memo[i/2] + i%2;
        }
        
        return memo;
    }
};
