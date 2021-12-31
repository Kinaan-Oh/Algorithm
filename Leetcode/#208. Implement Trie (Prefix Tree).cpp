// 출제의도: "Design", Time Complexity: O(n), Space Complexity: O(L) (n: 문자열 길이(삽입하고자/찾고자 하는), L: 삽입한 문자열 길이의 총합)
// 주로 재귀로 구현해왔지만, 스택 사용할 필요 없는 반복구조로 구현해봄.
// 용도: 1) 자동 완성(Autocomplete) 2) 맞춤법 검사(Spell checker) 3) IP 라우팅(최장 프리픽스 매칭) 4) Boggle 게임(백준 9202)
// Trie 자료구조는 "1) 같은 prefix를 같은 모든 문자열의 검색 2) 사전순 문자열 나열 3) 적은 공간으로 많은 문자열을 저장" 등의 이점이 있다
// 길이가 m인 문자열 탐색의 경우 BST가 O(mlgn)이 걸리는 반면, 트라이는 O(m)으로 우월하다.(n: BST 원소의 갯수) 

// 12/31 Refactor: 좀 더 간결하게 변경

class Trie {
private:
    unordered_map<char, Trie*>  children;
    bool is_tail;
    
public:
    Trie() {
        is_tail = false;
    }
    
    void insert(string word) {
        Trie* next = this;
        
        for(auto c: word) {
            if(next->children[c] == nullptr)    next->children[c] = new Trie();
            
            next = next->children[c];
        }
        next->is_tail = true;
    }
    
    bool search(string word) {
        Trie* next = this;
        
        for(auto c: word) {
            if(next->children[c] == nullptr)    return false;
            
            next = next->children[c];
        }
        return next->is_tail;
    }
    
    bool startsWith(string prefix) {
        Trie* next = this;
        
        for(auto c: prefix) {
            if(next->children[c] == nullptr)    return false;
            
            next = next->children[c];
        }
        return true;
    }
};
