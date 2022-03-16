// Math/Modular, Time Complexity: O(1), Space Complexity: O(1)
// 논리: 1) Modular로 해결하기위해 A:1 ~ Z:26 을 A:0 ~ Z:25 로 매핑 필요. 
//      2) 매핑을 위해 1을 빼주면 된다.

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string answer;
        
        do {
            columnNumber -= 1;
            answer.push_back('A'+columnNumber%26);
            columnNumber/=26;
        } while(columnNumber);
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
