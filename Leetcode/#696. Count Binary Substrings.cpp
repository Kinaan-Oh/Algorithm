// Math, Time Complexity: O(l), Space Complexity: O(l) (l: s.length)
// 수리적 해석이 필요한 문제. 첫 시도에 Brute-Forece로 시도하여 해결하지 못함.
// 0001111 에서 consecutive grouped substring의 갯수는 01, 0011, 000111으로 3이 된다. 패턴 관찰을 통해 min(3,4) => 3 임을 파악해야만 한다.
// 관련 수학적 지식이 있는 사람은 쉽게 해결했겠지만, 이 부분에 대한 지식이 없는 사람은 Brute-Force 풀이 정도에서 끝나는 것이 일반적일 것으로 판단.

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int>    group;
        int answer = 0;
        char prev = s[0];
        int cur = 0;
        
        group.push_back(0);
        
        for(int i=0;i<s.size();i++) {
            if(s[i] != prev) {
                group.push_back(1);
                prev = s[i];
                cur += 1;
            } else {
                group[cur] += 1;
            }
        }
        
        for(int i=1;i<group.size();i++) {
            answer += min(group[i-1], group[i]);
        }
        return answer;
    }
};
