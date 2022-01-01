// Sort, Time Complexity: O(nlgn), Space Complexity: O(k)
// 생각하기 가장 쉬운 풀이.

bool compare(vector<int> &a, vector<int> &b) {
    return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), compare);
        vector<vector<int>> answer(points.begin(), points.begin()+k);
        return answer;
    }
};
