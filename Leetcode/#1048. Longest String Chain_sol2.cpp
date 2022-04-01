// DP(Bottom-Up), Time Complexity: O(NlgN+NL^2), Space Complexity: O(N) (N: words.size, L: max length of words)
// 논리: sol1과 동일. Iterative Method로 Stack 사용(Recursion Method)을 회피할 수 있는 점에서 장점.

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int answer = 0;
        unordered_map<string,int>  memo;
        auto compare = [](string &a, string &b) {
            return a.length()<b.length();
        };
        
        sort(words.begin(), words.end(), compare);
        
        for(auto word: words) {
            int maxLength = 1;
            
            for(int i=0;i<word.size();i++) {
                string candidate = word.substr(0,i) + word.substr(i+1);
                
                if(memo.find(candidate) != memo.end()) {
                    maxLength = max(maxLength, 1 + memo[candidate]);
                }
            }
            memo[word] = maxLength;
            answer = max(answer, memo[word]);
        }
        return answer;
    }
};
