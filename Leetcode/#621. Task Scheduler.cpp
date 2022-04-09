// Greedy/Heap, Time Complexity: O(m), Space Complexity: O(m) (m: tasks.size)
// 논리: 1) there must be at least n units of time between any two same tasks 조건을 만족하기 위해 n+1 구간 단위 schedule.
//      2) n+1 구간 schedule시 다음 기준으로 선택. 1. 서로 다른 task 선택 2. count가 큰 task 우선선택.
//      2-1) count가 큰 task 우선선택 이유: diversity of the task pool를 maximize해야 구간 내 idle state를 minimize 할 수 있음.
//      3) n+1 구간 schedule시 schedule되지 못한 구간은 idle state.
// task는 A~Z로 26종. 따라서, heap operation time complexity ~= O(1). -> total time complexity: O(m).
// 90%수준의 풀이가 잘못된 풀이/greedy 수학적 증명이 필요한, 그러나 증명하지 않은 상태임에 제법 놀랐던 문제.

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)    return tasks.size();
        
        int answer = 0;
        unordered_map<char,int> count;
        priority_queue<int> maxHeap;
        
        for(auto task: tasks) {
            count[task] += 1;
        }
        for(auto e: count) {
            maxHeap.push(e.second);
        }
        
        while(!maxHeap.empty()) {
            vector<int> tmp;
            
            for(int i=0;i<n+1;i++) {
                if(!maxHeap.empty()) {
                    tmp.push_back(maxHeap.top());
                    maxHeap.pop();
                }
            }
            for(auto e: tmp) {
                if(--e>0) {
                    maxHeap.push(e);
                }
            }
            answer += (maxHeap.empty() ? tmp.size() : n+1);
        }
        return answer;
    }
};
