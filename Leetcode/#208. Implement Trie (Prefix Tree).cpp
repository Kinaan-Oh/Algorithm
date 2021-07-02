// 출제의도: "Design", Time Complexity: O(n), Space Complexity: O(L) (n: 문자열 길이(삽입하고자/찾고자 하는), L: 삽입한 문자열 길이의 총합)
// 주로 재귀로 구현해왔지만, 스택 사용할 필요 없는 반복구조로 구현해봄.

class Trie {
private:
    unordered_map<char,Trie*>   child;
    int num_of_tail;
    bool tail;
public:
    /** Initialize your data structure here. */
    Trie() {
        this->num_of_tail = 0;
        this->tail = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* cur = this;
        cur->num_of_tail += 1;
        
        for(int i=0;i<word.length();i++) {
            if(cur->child[word[i]]==nullptr)    cur->child[word[i]] = new Trie();
            cur = cur->child[word[i]];
            cur->num_of_tail += 1;
        }
        cur->tail = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* cur = this;
        for(int i=0;i<word.length();i++) {
            if(cur->child[word[i]]==nullptr)    return false;
            cur = cur->child[word[i]];
        }
        return cur->tail;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* cur = this;
        for(int i=0;i<prefix.size();i++) {
            if(cur->child[prefix[i]]==nullptr)    return false;
            cur = cur->child[prefix[i]];
        }
        return cur->num_of_tail;
    }
};
