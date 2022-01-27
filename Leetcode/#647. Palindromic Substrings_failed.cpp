// Brute-Force, Time Complexity: O(l^3), Space Complexity: O(1). (l: s.length)
// Time Limit Exceeded. 128 / 130 test cases passed.
// Brute-Force 구현을 위한 의도적 실패. 

class Solution {
public:
    int countSubstrings(string s) {
        int answer = 0;
        
        for(int i=0;i<s.length();i++) {
            for(int j=1;j<=s.length()-i;j++) {
                if(is_palindrome(s.substr(i,j)))    answer += 1;
            }
        }
        return answer;
    }
    
    bool is_palindrome(string s) {
        if(s.length()<=1)   return true;
        
        return s.front()==s.back() && is_palindrome(s.substr(1,s.length()-2));
    }
};
