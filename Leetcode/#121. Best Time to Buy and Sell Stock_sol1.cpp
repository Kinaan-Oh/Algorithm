// i번째 이후 최대 price를 메모이제이션하여 해결. Time Complexity: O(n), Space Complexity: O(n).

class Solution {
private:
    int max_after[100000];

public:
    int maxProfit(vector<int>& prices) {
        int max_profit=-1;
        int max_price=-1;
        for(int i=prices.size()-1;i>=0;i--) {
            max_price = max(max_price, prices[i]);
            max_after[i] = max_price;
        }
        for(int i=0;i<prices.size();i++) {
            max_profit = max(max_profit, max_after[i]-prices[i]);
        }
        return  max_profit; 
    }
};
