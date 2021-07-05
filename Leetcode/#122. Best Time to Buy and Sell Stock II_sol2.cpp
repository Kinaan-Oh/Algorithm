// "DP, Greedy", Time Complexity: O(n), Space Complexity: O(1). (n: prices.size)
// 2가지 state를 정의(stock을 1) 보유(hold)/ 2) 보유하지 않음(not hold))
// 초기 상태(cur_not_hold)는 stock을 보유하지 않고, 잔고가 0 원. cur_hold는 불가능한 상태이므로 INT_MIN으로 초기화.
// 순차적으로 prices을 순회하면서 각 날짜에 대해 cur_hold와 cur_not_hold를 최대화.(Greedy)
// cur_hold는 1) 전날 보유, 오늘 구매하지 않음 Or 2) 전날 보유하지 않음, 오늘 구매  의 2가지 케이스 중 더 큰 값으로 설정.
// cur_not_hold는 1) 전날 보유, 오늘 판매 Or 2) 전날 보유하지 않음, 오늘 구매하지 않음 의 2가지 케이스 중 더 큰 값으로 설정.
// 최종적으로 cur_not_hold(주식을 보유하지 않은 상태)을 리턴.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_hold = INT_MIN, cur_not_hold = 0;
        
        for(int i=0;i<prices.size();i++) {
            int prev_hold = cur_hold, prev_not_hold = cur_not_hold;
            
            cur_hold = max(prev_hold, prev_not_hold - prices[i]);
            cur_not_hold = max(prev_not_hold, prev_hold + prices[i]);
        }
        return cur_not_hold;
    }
};
