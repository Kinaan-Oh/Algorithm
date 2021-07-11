// "DP - Top Down", Time Complexity: O(n^2), Space Complexity: O(n^2) (n: s.length)
// 점화식: 부분 문자열 i~j가 Palindrome이기 위해서는 1) s[i]==s[j] 이고 2) 부분 문자열 i+1~j-1가 Palindrome 이어야만 한다.
// sol1과는 다르게 긴 문자열부터 Palindrome인지 확인(Greedy). 부분 문자열의 Palindrome 여부를 memoize하여 재사용.
// Greedy한 접근으로 sol1보다 성능이 근소하게 우수.

class Solution {
private:
    int memo[1000][1000];
public:
    string longestPalindrome(string s) {
        fill(&memo[0][0],&memo[0][0]+1000*1000,0);
        for(int i=0;i<s.length();i++)   memo[i][i] = 1;
        for(int l=s.length();l>=1;l--) {
            for(int i=0;i+l-1<s.length();i++) {
                if(isPalindrome(s,i,i+l-1)) return s.substr(i,l);
            }
        }
        return "";
    }
    
    bool isPalindrome(string &s, int begin, int end) {
        if(memo[begin][end])    return (memo[begin][end]==-1 ? false : true);
        if(begin>=end)   return true;
        
        memo[begin][end] = ((s[begin]==s[end] && isPalindrome(s,begin+1,end-1)) ? 1 : -1);
        return (memo[begin][end]==1 ? true : false);
    }
};
