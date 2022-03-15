// Math(Carry), Time Complexity: O(max(m,n)), Space Complexity: O(1) (m: a.length, n: b.length)

class Solution {
public:
    string addBinary(string a, string b) {
        string answer;
        int p1 = a.size()-1;
        int p2 = b.size()-1;
        int carry = 0;
        
        while(p1>=0 || p2>=0) {
            int d1 = p1>=0 ? a[p1]-'0' : 0;
            int d2 = p2>=0 ? b[p2]-'0' : 0;
            int cur = (d1+d2+carry)%2;
            carry = (d1+d2+carry)/2;
            answer.push_back('0'+cur);
            p1 -= 1;
            p2 -= 1;
        }
        if(carry>0)    answer.push_back('1');
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
