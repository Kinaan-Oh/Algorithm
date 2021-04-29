// Trie 자료구조. Time Complexity: O(L), Space Complexity: O(L).

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Trie {
    int numOfTail;
    Trie *next[26];
    Trie() {
        fill(next,next+26,nullptr);
        numOfTail=0;
    }
    
    void insert(string &word, int cur) {
        numOfTail++;
        if(cur==word.length())  return;
        if(next[word[cur]-'a']==nullptr) next[word[cur]-'a'] = new Trie();
        return next[word[cur]-'a']->insert(word,cur+1);
    }
    
    int find(string &word, int cur) {
        if(numOfTail==1 || cur==word.length())  return cur;
        return next[word[cur]-'a']->find(word,cur+1);
    }
};

int solution(vector<string> words) {
    int answer = 0;
    Trie trie;
    for(int i=0;i<words.size();i++) {
        trie.insert(words[i],0);
    }
    for(int i=0;i<words.size();i++) {
        answer += trie.find(words[i],0);
    }
    return answer;
}
