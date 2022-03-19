// Sort, Time Complexity: O(nlgn), Space Complexity: O(n: num of intervals)
// 논리: right most end time을 memoize하기 위해 rightmost 선언. if new interval is higher than rightmost -> we find free timeinterval.

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval>    answer;
        vector<Interval>    input;
        int rightmost = 0;
        
        for(int i=0;i<schedule.size();i++) {
            for(int j=0;j<schedule[i].size();j++) {
                input.push_back(schedule[i][j]);
            }
        }
        
        sort(input.begin(), input.end(), [](Interval a, Interval b) {
            return a.start<b.start;
        });
            
        for(auto interval: input) {
            if(rightmost>0 && rightmost<interval.start) {
                answer.push_back(Interval(rightmost, interval.start));
            }
            rightmost = max(rightmost, interval.end);
        }     
        return answer;
    }
};
