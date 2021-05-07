// 출제의도: "트라이" Time Complexity: O(모든 쿼리 길이의 합), Space Complexity: O(모든 단어 길이의 합)
// [논리 흐름]
// 1. ??app과 같은 접미사를 처리하기 위해, reverse 시켜 트라이(접두사 트리)로 관리할 수 있음.
// 2. app??, app???, app???? 가 접두사 "app"인 서로 다른 길이의 단어를 의미하므로 일반 트라이 1개로는 구분하기 어려움.
// -> 서로 다른 길이의 단어 별로 트라이를 각각 유지하면 해결 할 수 있을 것 같지만, 많은 메모리를 사용하므로 메모리 초과가 염려되어 진행하지 않았고 1개의 트라이로 복잡한 구현(모든 길이 단어 저장)을 했으나 시간초과
// 발생. 1개 트리아로 구현할 경우, 해당 단어의 길이에 대응하는 깊이의 트라이 노드들을 전부 확인해주는 비효율이 발생했으나(접두사만으로 구할 수 없음), 후자의 경우 접두사만 탐색하면 갯수를 구할 수 있으므로 훨씬 효율적.
// -> 제한조건으로 전체 가사 단어 길이의 합은 10^6개 이하임이 제시됨. 트라이 노드 1개당 108byte 이므로 최악의 경우 1.08*10^8 바이트(<1기가 바이트)가 필요함. 매우 큰 메모리를 사용하므로 메모리 초과를 강하게
// 의심하였고, "카카오 코테는 메모리 제한에 대한 조건이 주어지지 않아서" 이 방향으로 진행할 지, 말지에 대한 논리적 판단이 불가능하였음. 따라서, 진행하지 않았고 풀지 못하는 결과를 얻음.
// -> 메모리 제한에 대한 언급이 없었으므로, 일단 진행하는 선택을 했어야 했음.(대부분의 문제는 1giga byte 메모리 사용이 메모리 초과가 발생하지만) 그것을 후회함.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Trie {
    int num_of_words;
    Trie * children[26];    //  [0:'a'] ~ [25:'z']
    
    Trie() {
        num_of_words = 0;
        fill(children, children+26, nullptr);
    }
    
    void insert(string &word, int pos) {
        num_of_words++;
        if(pos==word.length())  return;
        if(children[word[pos]-'a']==nullptr)    children[word[pos]-'a'] = new Trie();
        children[word[pos]-'a']->insert(word, pos+1);
    }
    
    int find(string &query, int pos) {
        if(query[pos]=='?') return num_of_words;
        if(children[query[pos]-'a']==nullptr)   return 0;
        return  children[query[pos]-'a']->find(query,pos+1);
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie trie_prefix[10001], trie_suffix[10001];    // idx: 1~10000
    for(int i=0;i<words.size();i++) {
        string word = words[i];
        int word_length = word.length();
        trie_prefix[word_length].insert(word,0);
        reverse(word.begin(),word.end());
        trie_suffix[word_length].insert(word,0);
    }
    for(int i=0;i<queries.size();i++) {
        int query_length = queries[i].length();
        if(queries[i][0]=='?') {
            reverse(queries[i].begin(),queries[i].end());
            answer.push_back(trie_suffix[query_length].find(queries[i],0));
        }
        else    answer.push_back(trie_prefix[query_length].find(queries[i],0));
    }
    return answer;
}
