// Greedy, Time Complexity: O(n), Space Complexity: O(1) (n: position.size)
// 논리: 1. 각 position에서 홀수번째 cost = 1, 짝수번째 cost = 0.
//      2. 1에 따라 임의의 짝수번째 position의 총비용은 같고, 마찬가지로 임의의 홀수번째 positino의 총비용은 같다.
//      3. 2에 따라 pos 1(홀수), 2(짝수)에 대한 총비용중 최소값이 해가된다.

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int evenCount = 0;
        int oddCount = 0;
        
        for(auto pos: position) {
            if(pos%2) {
                evenCount += 1;
            } else {
                oddCount += 1;
            }
        }
        return min(oddCount, evenCount);
    }
};
