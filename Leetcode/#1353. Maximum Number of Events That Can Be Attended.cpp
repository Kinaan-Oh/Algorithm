// Greedy/Heap, Time Complexity: O(nlgn), Space Complexity: O(n) (n: events.size)
// 논리: 1) 현 시점 기준 overlaped events 중 endTime이 minimum인 event을 schedule 한다.
//      1-1) 현 시점 기준 begining event를 efficient probe 위해 sort 사용.(heap 역시 가능)
//      1-2) endTime minumum event를 efficient probe를 위해 heap 사용.
// SK 2차코테 2번과 유사. 비슷한 로직으로 풀이.

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int answer = 0;
        sort(events.begin(), events.end());
        auto compare = [](int a, int b) {
            return a>b;
        };
        priority_queue<int, vector<int>, decltype(compare)> minHeap(compare);
        int i=0;
        
        for(int d=1;d<=100000;d++) {
            while(!minHeap.empty() && minHeap.top()<d) {
                minHeap.pop();
            }
            
            while(i<events.size() && events[i][0]==d) {
                minHeap.push(events[i++][1]);
            }
            
            if(!minHeap.empty()) {
                minHeap.pop();
                answer += 1;
            }
        }
        return answer;
    }
};
