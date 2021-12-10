// 출제의도 : "DFS", Time Complexity: O(4^n), Space Complexity: O(n). (n: digits.length)
// 문제 입력 크기(digits.length) <= 4 로 매우 작음. 따라서, Brute Force한 풀이인 DFS를 선택.

class Solution {
private:
    unordered_map<char, string> ht;
    vector<string> answer;
    
public:
    vector<string> letterCombinations(string digits) {
        init();
        generateLetterCombinations(digits, "", 0);
        
        return answer;
    }
    
    void generateLetterCombinations(string &digits, string letter, int digits_index) {
        if(digits_index == digits.length()) {
            answer.push_back(letter);
            return;
        }
        
        for(int i=0;i<ht[digits[digits_index]].length();i++) {
            generateLetterCombinations(digits, letter+ht[digits[digits_index]][i] , digits_index+1);
        }
    }
    
    void init() {
        ht['2'] = "abc";
        ht['3'] = "def";
        ht['4'] = "ghi";
        ht['5'] = "jkl";
        ht['6'] = "mno";
        ht['7'] = "pqrs";
        ht['8'] = "tuv";
        ht['9'] = "wxyz";
    }
};
