// Hash, Time Complexity: O(n), Space Complexity: O(n) (n: s.length)

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int>    ht;
        
        for(auto c: s) {
            ht[c] += 1;
        }
        
        for(int i=0;i<s.length();i++) {
            if(ht[s[i]]==1) {
                return  i;
            }
        }
        return -1;
    }
};
