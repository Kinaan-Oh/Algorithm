// sol1의 max_after[]을 사용하지 않아도 one-pass로 문제해결이 가능. Time Complexity: O(n), Space Complexity: O(1).

class Solution {
private:

public:
    int maxProfit(vector<int>& prices) {
        int max_profit=-1;
        int max_price=-1;
        for(int i=prices.size()-1;i>=0;i--) {
            max_price = max(max_price, prices[i]);
            max_profit = max(max_profit, max_price-prices[i]); // 추가된 부분
        }
        return  max_profit; 
    }
};
