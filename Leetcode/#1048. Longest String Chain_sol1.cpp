// DP(Top-Down), Time Complexity: O(NL^2), Space Complexity: O(N) (N: num of words, L: max length of words)
// 논리: Longest String Chain of w = max(Longest String Chain of substring of w(delete exactly one char))

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int answer = 0;
        unordered_map<string,int>  memo;
        unordered_set<string>  wordsPresent;
        
        for(auto word: words) {
            wordsPresent.insert(word);
        }
        
        for(auto word: words) {
            answer = max(answer, dfs(memo, wordsPresent, word));
        }
        return answer;
    }
    
    int dfs(unordered_map<string,int> &memo, unordered_set<string> &wordsPresent, string word) {
        if(memo.find(word) != memo.end()) {
            return memo[word];
        }
        
        int maxLength = 1;
        
        for(int i=0;i<word.size();i++) {
            string predecessor = word.substr(0,i) + word.substr(i+1);
            
            if(wordsPresent.find(predecessor) != wordsPresent.end()) {
                maxLength = max(maxLength, 1 + dfs(memo, wordsPresent, predecessor));
            }
        }
        memo[word] = maxLength;
        return memo[word];
    }
};
