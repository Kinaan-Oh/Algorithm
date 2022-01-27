// Recursion with Memoization, Time Complexity: O(l^2), Space Complexity: O(l^2) (l: s.length)
// memoization으로 is_palindrome의 중복계산 해결.

class Solution {
private:
    optional<bool>  dp[1000][1000];
    
public:
    int countSubstrings(string s) {
        int answer = 0;
        
        fill(&dp[0][0], &dp[999][999]+1, nullopt);
        
        for(int i=0;i<s.length();i++) {
            for(int j=1;j<=s.length()-i;j++) {
                if(is_palindrome(s, i, i+j))    answer += 1;
            }
        }
        return answer;
    }
    
    bool is_palindrome(string &s, int begin, int end) {
        if(end-begin<=1)    return true;
        else if(dp[begin][end] != nullopt)   return dp[begin][end] == true;
        
        dp[begin][end] = s[begin]==s[end-1] && is_palindrome(s, begin+1, end-1);
        return dp[begin][end] == true;
    }
};
