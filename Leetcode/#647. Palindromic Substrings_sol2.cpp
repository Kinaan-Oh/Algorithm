// Bottom-Up DP, Time Complexity: O(l^2), Space Complexity: O(l^2) (l: s.length)
// time/space complexity는 sol1과 동일. 
// sol1의 단점은 recursion으로 인한 callstack 사용인데 callstack의 space complexity는 worstcase의 경우 O(n) 수준으로 전체 time complexity에 영향을 주지 못하지만.. 약간의 개선 효과는 있다.
// 몇몇 문제의 경우 callstack space complexity가 전체 space complexity를 좌우하는 경우가 있기에 Bottom-Up DP가 Top-Down DP(Recursion with memo)보다 일반적으로 효율적이므로 연습삼아 구현하였다.

class Solution {
private:
    optional<bool>  dp[1000][1000];
    
public:
    int countSubstrings(string s) {
        int answer = 0;
        
        fill(&dp[0][0], &dp[999][999]+1, nullopt);
        
        for(int l=1;l<=s.length();l++) {
            for(int i=0;i<s.length();i++) {
                if(l==1) {
                    dp[i][i] = true;
                    answer += 1;
                } else if(l==2 && i+1<s.length()) {
                    dp[i][i+1] = (s[i]==s[i+1]);
                    if(dp[i][i+1] == true)    answer += 1;
                } else if(l>2 && i+l-1<s.length()) {
                    dp[i][i+l-1] = (s[i]==s[i+l-1] && dp[i+1][i+l-2]==true);
                    if(dp[i][i+l-1] == true)    answer += 1;
                }
            }
        }
        return answer;
    }
};
