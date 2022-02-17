// Trie, Time Complexity: O(L), Space Complexity: O(L) (L: sum of length of str)

class Trie {
    private:
        unordered_map<char, Trie*>  children;
    
    public:
        string insert(string word) {
            Trie* cur = this;
            string commonPrefix;
            
            for(auto c: word) {
                if(cur->children[c] == nullptr) {
                    cur->children[c] = new Trie();
                } else {
                    commonPrefix.push_back(c);
                }
                cur = cur->children[c];
            }
            return commonPrefix;
        }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)  return strs[0];
        
        string answer;
        Trie trie = Trie();
        
        trie.insert(strs[0]);
        for(int i=1;i<strs.size();i++) {
            string prefix = trie.insert(strs[i]);
            
            if(prefix.empty())  return "";
            else if(answer.empty() || prefix.size()<answer.size()) {
                answer = prefix;
            }
        }
        
        return answer;
    }
};
