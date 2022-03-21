// Greedy/Heap, Time Complexity: O(nlgn), Space Complexity: O(n) (n: stations.size)
// 논리: 1) 현재 fuel로 최대한 충전하지 않고 멀리가야만 한다(Greedy).
//      2) 현재 fuel 기준 도달불가능한 최초 station에 도달한다면, 직전 station들의 set중 최대 fuel 충전이 가능한 station(Greedy)에서 충전한다. 
//      2-1) 직전 stations을 fuel 기준 max heap으로 유지한다면, O(lgn)으로 탐색할 수 있다.(선형탐색의 경우 O(n))
//      3) 2를 반복하고, 마지막으로 target에 대해 1회 진행한다.

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int answer = 0;
        int prevPos = 0;
        int curFuel = startFuel;
        priority_queue<int>  maxHeap;
        
        for(auto station: stations) {
            curFuel -= (station[0]-prevPos);
                
            while(!maxHeap.empty() && curFuel<0) {
                curFuel += maxHeap.top();
                maxHeap.pop();
                answer += 1;
            }    
            if(curFuel<0)   return -1;
            
            prevPos = station[0];
            maxHeap.push(station[1]);
        }
        
        curFuel -= (target-prevPos);
        while(!maxHeap.empty() && curFuel<0) {
            curFuel += maxHeap.top();
            maxHeap.pop();
            answer += 1;
        }    
        if(curFuel<0)   return -1;
        
        return answer;
    }
};
