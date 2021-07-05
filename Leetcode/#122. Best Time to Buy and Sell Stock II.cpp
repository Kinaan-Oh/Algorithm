// 출제의도: "Greedy", Time Complexity: O(n), Space Complexity: O(1). (n: prices.size)
// 극점(감소->증가 or 증가->감소)에서 구매 or 판매.
// 극소점에서 구매, 극대점에서 판매.
// 극소점에서 구매 후 함수 내 최대값인 지점에서 판매를 고려할 수 있지만, 최대값 도달 전에 극대점이 있다면 그 지점에서 판매하는 것이 이익이 더 크다. 때문에, 극소점에서 구매 후 , 다음 극대점에서 판매한다.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int i=0, sz = prices.size();
        int valley=0, peak=0;
        
        while(i!=sz-1) {
            while(i<sz-1 && prices[i]>=prices[i+1]) {
                i++;
            }
            valley = i;
            while(i<sz-1 && prices[i]<=prices[i+1]) {
                i++;
            }
            peak = i;
            profit += (prices[peak] - prices[valley]);
        }
        
        return profit;
    }
};
