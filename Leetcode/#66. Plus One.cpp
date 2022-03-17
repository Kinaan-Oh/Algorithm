// Math(Carry), Time Complexity: O(n), Space Complexity: O(n) (n: digits.size)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> answer;
        int n = digits.size();
        int carry = 1;
        
        for(int i=n-1;i>=0;i--) {
            if(carry==0)    break;
            
            int sum = carry+digits[i];
            digits[i] = sum%10;
            carry = sum/10;
        }
        if(carry)   answer.push_back(1);
        for(auto digit: digits)    answer.push_back(digit);
        return answer;
    }
};
