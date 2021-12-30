// Try: Brute-Froce, Time Complexity: O(n^3), Space Complexity: O(n^2). (n: words.size)
// 84 / 136 test cases passed. Time Limit Exceeded.

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> answer;
        
        for(int i=0;i<words.size();i++) {
            for(int j=i+1;j<words.size();j++) {
                if(isPalindrome(words[i]+words[j])) answer.push_back({i,j});
                if(isPalindrome(words[j]+words[i])) answer.push_back({j,i});
            }
        }
        return answer;
    }
    
    bool isPalindrome(string s) {
        for(int i=0;i<s.size()/2;i++) {
            if(s[i] != s[s.size()-1-i])   return false;
        }
        return true;
    }
};
