// "Brian Kernighan 알고리즘", Time Complexity: O(n), Space Complexty: O(n).
// sol1의 Brian Kernighan 알고리즘은 각 비트열의 1이 갯수를 count하는 횟수를 줄이는데 사용했지만, Time Complexity O(nlgn)으로 비효율적.
// i와 i&(i-1) 의 1의 갯수에 대해 점화식을 세울 수 있다.
// 점화식: "i의 1의 갯수 = i&(i-1)의 1의 갯수 + 1". (i&(i-1) < i 이므로 i&(i-1)은 memoize한 값을 이용.)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        
        for(int i=1;i<=n;i++) {
            ans[i] = ans[i&(i-1)] + 1;
        }
        return ans;
    }
};
