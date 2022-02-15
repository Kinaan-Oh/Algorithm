// Brute-Force With Memoization, Time Complexity: O(l^2), Space Complexity: O(2^l). (l: s.length)
// 예상대로 Time Limit Exceeded, 282 / 467 test cases passed.

class Solution {
private:
    unordered_map<string, bool>  dp;
    
public:
    bool validPalindrome(string s) {
        if(isPalindrome(s))    return true;
        for(int i=0;i<s.length();i++) {
            if(isPalindrome(s.substr(0,i) + s.substr(i+1))) {
                return true;
            }
        }
        return false;
    }
    
    bool isPalindrome(string s) {
        if(dp[s])   return true;
        else if(s.length()<=1)   return true;
        
        dp[s] = s.front()==s.back() && isPalindrome(s.substr(1,s.length()-2));
        return dp[s];
    }
};
