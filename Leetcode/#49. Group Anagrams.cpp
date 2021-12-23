// 출제의도: string/count, Time Complexity: O(L), Space Complexity: O(L). (L: strs의 모든 문자열 길이의 합)
// 첫 시도에서 count를 16진수 비트마스크를 시도했지만, 같은 문자가 최대 100회 중복될 수 있는 조건 때문에 accept 받지 못하였음. 
// 100진수 개념을 만들수도 있었겠지만, 문자열로 count개념을 표현하는 단순한 방법 채택.

tring count(string str) {
    string count = string(26,'0');
    
    for(auto c: str) {
        count[c-'a'] += 1;
    }
    return count;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>  answer;
        unordered_map<string, vector<string>>  anagrams; // [count: group]
        
        for(auto str: strs) {
            anagrams[count(str)].push_back(str);
        }
        for(auto anagram: anagrams) {
            answer.push_back(anagram.second);
        }
        return answer;
    }
};
