// Math, Time Complexity: O(n), Space Complexity: O(1) (n: columnTitle.size)
// 첫 시도 d를 int로 선언하여 over flow. n은 최대 7이므로 long long 타입으로 선언 필요.

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int answer = 0;
        long long d = 1;
        
        for(int i=columnTitle.size()-1;i>=0;i--) {
            answer += d*(columnTitle[i]-'A'+1);
            d *= 26;
        }
        return answer;
    }
};
