// Sliding Window/Hash Table, Time Complexity: O(s+p), Space Complexity: O(1) (s: s.length, p: p.length)
// 기존 multiset을 사용한 풀이는 s, p의 length가 크기 때문에 적절하지 못한 방법. (생성 time complexity와 space complexity가 length에 비례)
// 단순 Hash Table([alphabet: num of alphabet])을 사용하면 alphabet의 갯수(26)만큼 space complexity는 O(1)이 되고, 때문에 hash table간 비교 연산 또한 O(1)이 된다.

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int>    ht_s;
        unordered_map<char, int>    ht_p;
        vector<int> answer;
        
        for(auto c: p)  ht_p[c] += 1;
        for(int i=0;i<s.length();i++) {
            int prev = i-(int)p.length();
            
            if(prev>=0 && --ht_s[s[prev]] == 0)    ht_s.erase(s[prev]);
            ht_s[s[i]] += 1;
            if(ht_s == ht_p)    answer.push_back(prev+1);
        }
        return answer;
    }
};
