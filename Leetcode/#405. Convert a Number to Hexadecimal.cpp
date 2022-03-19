// Math, Time Complexity: O(1), Space Complexity: O(1)

class Solution {
public:
    string toHex(int num) {
        unsigned int input = num;
        vector<char> hex = {'0','1','2','3','4','5','6','7',
                            '8','9','a','b','c','d','e','f'};
        string answer;
        
        while(input) {
            answer = hex[input&(15)] + answer;
            input >>= 4;
        }
        return answer.empty() ? "0" : answer;
    }
};
