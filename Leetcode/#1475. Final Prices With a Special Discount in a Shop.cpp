// Stack, Time Complexity: O(n), Space Complexity: O(n) (n: prices.size)
// 논리: 1) 문제: prices 각 elem에 대하여 해당 elem보다 작거나 같은 최초의 우측 원소를 찾기
//      2) stack은 monoton increasing하게 elem을 보관하고, stack의 top보다 작거나 같은 원소를 만나면 pop하여 answer를 update.

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> answer(prices.begin(), prices.end());
        stack<int>  stk;
        
        for(int i=0;i<prices.size();i++) {
            while(!stk.empty() && prices[stk.top()]>=prices[i]) {
                answer[stk.top()] -= prices[i];
                stk.pop();
            }
            stk.push(i);
        }
        return answer;
    }
};
