// n<=8의 작은 입력으로 Brute-Force한 풀이 가능.
// 순열(next_permutation)을 이용하여 모든 경우의 Parentheses를 생성하고(O(n*2nCn)), 각 경우를 검증(O(n)).
// Time Complexity : O(n^2*2nCn), Space Complexity: O(2nCn).


class Solution {
private:
    vector<string> answer;
    string parentheses;
    
public:
    vector<string> generateParenthesis(int n) {
        init(n);
        do {
            if(verify(parentheses)) {
                answer.push_back(parentheses);
            }
        } while(next_permutation(parentheses.begin(), parentheses.end()));
        
        return answer;
    }
    
    void init(int n) {
        for(int i=0;i<n;i++) {
            parentheses += "(";
        }
        
        for(int i=0;i<n;i++) {
            parentheses += ")";
        }
    }
    
    bool verify(string parentheses) {
        int sum = 0;
        
        for(int i=0;i<parentheses.length();i++) {
            if(parentheses[i] == '(') {
                sum += 1;
            } else {
                sum -= 1;
            }
            
            if(sum<0) {
                return false;
            }
        }
        
        return true;
    }
};
