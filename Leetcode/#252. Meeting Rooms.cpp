// Sort, Time Complexity: O(nlgn), Space Complexity: O(1) (n: intervals.size)
// Kakao에 2회 출제된 문제.
// overlap 여부 판단로직을 이용하여 Brute-Force한 O(n^2) 풀이 가능. Kakao에서 overlap 풀이도 통과했었음.

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i-1][1]>intervals[i][0]) {
                return false;
            }
        }
        return true;
    }
};
