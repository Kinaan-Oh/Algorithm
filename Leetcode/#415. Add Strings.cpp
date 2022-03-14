// Math, Time Complexity: O(max(l1,l2)), Space Complexity: O(1) (l1: num1.length, l2:num2.length)
// Facebook 출제

class Solution {
public:
    string addStrings(string num1, string num2) {
        string answer;
        int p1 = num1.size()-1;
        int p2 = num2.size()-1;
        int carry = 0;
        
        while(p1>=0 || p2>=0) {
            int n1 = p1>=0 ? num1[p1]-'0' : 0;
            int n2 = p2>=0 ? num2[p2]-'0' : 0;
            int val = (n1+n2+carry)%10;
            carry = (n1+n2+carry)/10;
            answer += ('0'+val);
            p1-=1;
            p2-=1;
        }
        if(carry>0) answer += ('0'+carry);
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
