// Greedy, Time Complexity: O(n), Space Complexity: O(n) (n: bills.size)
// 논리: $20를 받은 경우, 거슬러주는 방법은 다음 2가지 방법이 있다. 1) $10:1 $5:1, 2) $5:3
//      1)방법을 높은우선순위로 결정한다는 측면에서 Greedy Approach가 된다.
//      1)방법을 우선하는 이유: $5는 $10, $20을 거슬러줄수 있는 반면, $10은 $20만 거슬러 줄수 있다. $10을 우선소모하고 $5를 남겨두어야 추후 $10을 거슬러줄 기회를 높일 수 있다.

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int>    change;
        
        if(bills[0]!=5)    return false;
        change[bills[0]] += 1;
        
        for(int i=1;i<bills.size();i++) {
            if(bills[i]==5) {
                change[bills[0]] += 1;
            } else if(bills[i]==10) {
                if(change[5]==0)    return false;
                change[5] -= 1;
                change[10] += 1;
            } else {
                if(change[10]>0 && change[5]>0) {
                    change[10] -= 1;
                    change[5] -= 1;
                } else if(change[5]>=3) {
                    change[5] -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
