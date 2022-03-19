// Heap, Time Complexity: O(nlgn), Space Complexity: O(n: num of intervals)
// 논리: right most end time을 memoize하기 위해 max heap datastructure 선택. if interval is higher than rightmost interval in heap -> we find free timeinterval.

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval>    answer;
        vector<Interval>    input;
        priority_queue<int>  maxHeap;
        
        for(int i=0;i<schedule.size();i++) {
            for(int j=0;j<schedule[i].size();j++) {
                input.push_back(schedule[i][j]);
            }
        }
        
        sort(input.begin(), input.end(), [](Interval a, Interval b) {
            return a.start<b.start;
        });
            
        for(auto interval: input) {
            if(!maxHeap.empty() && maxHeap.top()<interval.start) {
                answer.push_back(Interval(maxHeap.top(), interval.start));
            }
            maxHeap.push(interval.end);
        }     
        return answer;
    }
};
