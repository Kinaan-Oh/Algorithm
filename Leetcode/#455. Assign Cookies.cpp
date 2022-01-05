// 출제의도: Greedy/Sort, Time Complexity: O(nlgn+mlgm), Space Complexity: O(1) (n: g.size, m: s.size)
// 작은 쿠키는 최대한 불만이 없는 아이에게 제공되어야 함. 혹은 큰 쿠키는 최대한 불만이 많은 아이에게 제공되어야 함. 
// 전자의 idea로 풀이. Sort를 선택했지만, bst/heap 을 사용할 수 도 있음.(space complexity는 sort보다 좋지 못함)

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int answer = 0;
        int idx = 0;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        
        for(auto elem: s) {
            if(idx>=g.size())    break;
            if(g[idx]<=elem) {
                answer += 1;
                idx += 1;
            }
        }
        return answer;
    }
};
