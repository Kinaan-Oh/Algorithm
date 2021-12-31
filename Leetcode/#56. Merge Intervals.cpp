// 출제의도: Sort, Time Complexity: O(nlgn), Space Complexity: O(n) (n: intervals.size)
// Kakao, EBay 등 여러 코테에서 풀어봤던 유형.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        sort(intervals.begin(),intervals.end());
        vector<int> v = intervals[0];
        
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0] <= v[1]){
                v[1] = max(intervals[i][1],v[1]);
            }
            else{
                ans.push_back(v);
                v = intervals[i];
            }
        }
        ans.push_back(v);
        return ans;
    }
};
