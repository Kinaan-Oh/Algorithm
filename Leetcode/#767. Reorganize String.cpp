// Greedy/Heap/Hash, Time Complexity: O(nlgn), Space Complexity: O(L) (L: s.length)
// 논리: 1) most frequent한 char를 둘을 뽑아 교대로 배치하면 two adjacent characters are not the same을 보장한다.
//      1-1) 1)은 전체 해집합의 부분해에 지나지 않는다.
//      2) char의 frequency를 hash에 memoize
//      3) memoize된 frequency를 바탕으로 heap을 이용하여 효율적으로 frequency 우선 탐색가능 (frequency가 동일한 경우, lexicographically order로 리턴처리 하지 않으면 오류)
//      4) 배치중 adjacent char이 same인 경우 예외처리. ("" 리턴)

class Solution {
public:
    string reorganizeString(string s) {
        string answer;
        unordered_map<char, int>  count;
        auto compare = [](pair<char,int> &a, pair<char,int> &b) {
            return a.second<b.second || (a.second==b.second && a.first>b.first);
        };
        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(compare)>  maxHeap(compare);
        
        for(auto c: s) {
            count[c] += 1;
        }
        for(auto p: count) {
            maxHeap.push(p);
        }
        while(!maxHeap.empty()) {
            pair<char,int>  p1 = maxHeap.top();
            maxHeap.pop();
            
            if(!answer.empty() && answer.back()==p1.first)  return "";
            answer += p1.first;
            
            if(!maxHeap.empty()) {
                pair<char,int>  p2 = maxHeap.top();
                maxHeap.pop();
                
                answer += p2.first;
                
                if(p2.second>1) {
                    maxHeap.push({p2.first, p2.second-1});
                }
            }
            if(p1.second>1) {
                maxHeap.push({p1.first, p1.second-1});
            }
        }
        return answer;
    }
};
