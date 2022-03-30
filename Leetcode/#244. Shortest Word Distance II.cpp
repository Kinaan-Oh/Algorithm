// Two-Pointer, Time Complexity: O(n), Space Complexity: O(n) (n: wordsDict.size)
// 논리: 1) 중복문자 존재 가능. 따라서, 문자열에 대한 인덱스를 유지할 자료구조 필요. Hash, Vector 채택하여 보관. 순차대로 초기화(O(N))시 Vector는 따로 정렬할 필요없음.
//      2) Vetor내 index는 정렬된 상태이므로, 두 문자열에 대해 Two-Pointer 기법 적용가능. Time Complexity O(K+L) (K,L은 두 문자열 각각의 길이)으로 최소 index gap 추척가능.

class WordDistance {
private:
    unordered_map<string, vector<int>>  ht;
public:
    WordDistance(vector<string>& wordsDict) {
        for(int i=0;i<wordsDict.size();i++) {
            ht[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int answer = INT_MAX;
        int p1 = 0; int p2 = 0;
        
        if(ht.find(word1)==ht.end() || ht.find(word2)==ht.end()) {
            return 0;
        }
        
        while(p1<ht[word1].size() && p2<ht[word2].size())  {
            answer = min(answer, abs(ht[word1][p1]-ht[word2][p2]));
            
            if(ht[word1][p1]<ht[word2][p2]) {
                    p1 += 1;
            } else {
                p2 += 1;
            }
        }
        return answer;
    }
};
