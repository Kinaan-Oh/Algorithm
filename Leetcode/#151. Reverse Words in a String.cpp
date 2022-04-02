// String, Time Complexity: O(n^2), Space Complexity: O(n) (n: s.length)
// two-pointer를 이용해 reverse를 구현하는 것이 출제의도지만, 간략한 풀이를 위해 time complexity상 비효율적인 방법 적용.

class Solution {
public:
    string reverseWords(string s) {
        vector<string>  v;
        stringstream stream(s);
        string word;
        
        stream>>s;
        while(stream>>word) {
            s = word + " " + s;
        }
        return s;
    }
};
