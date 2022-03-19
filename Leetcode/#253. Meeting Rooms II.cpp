// Greedy/Heap, Time Complexity: O(nlgn), Space Complexity: O(n) (n: intervals.size)
// 논리: 1) random shuffled intervals을 sort한 뒤, time lower->higher order로 search
//      2) overlapped intervals을 maintain하기 위해 minHeap structure 선택. interval의 end time이 minimum인 interval과 new interval의 begin 값을 비교하기 용이하기 때문.

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int answer = 0;
        priority_queue<int, vector<int>, greater<int>>  minHeap;
        
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a<b;
        });
        for(auto interval: intervals) {
            while(!minHeap.empty() && minHeap.top()<=interval[0]) {
                minHeap.pop();
            }
            minHeap.push(interval[1]);
            answer = max(answer, (int)minHeap.size());
        }    
        return answer;
    }
};
