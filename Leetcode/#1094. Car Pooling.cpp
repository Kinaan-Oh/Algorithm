// Heap/Simulation, Time Complexity: O(nlgn), Space Complexity: O(n) (n: trips.size)
// 논리: 1) 'from' increasing order sort preprocess 필요
//      2) 각 지점 도착시, 이미 태운 승객들 중 내릴 수 있는 승객 먼저 내려야 함.
//      2-1) 이를 위해 도착점이 현재 지점보다 같거나 작은 승객들을 탐색해야만 하는데, heap struct를 통해 O(lgn) 으로 효율적 탐색 가능.
//      2-2) 따라서, 'to' 기준 min heap을 유지.
//      3) Simulation 중 탐승승객수가 capacity보다 크면, 중단 후 false. 같거나 작으면, 진행.
// 몇일전에 치른 SK 2차코테 2번과 아주 약간 유사.

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](vector<int> &a, vector<int> &b) {
            return a[1]<b[1] || (a[1]==b[1] && a[2]<b[2]);
        });
        
        auto compare = [](vector<int> &a, vector<int> &b) {
            return a[2]>b[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)>  minHeap(compare);
        int passengers = 0;
        
        for(auto trip: trips) {
            while(!minHeap.empty() && minHeap.top()[2]<=trip[1]) {
                passengers -= minHeap.top()[0];
                minHeap.pop();
            }
            
            passengers += trip[0];
            minHeap.push(trip);
            if(passengers>capacity)  return false;
        }
        return true;
    }
};
