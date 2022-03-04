// Greedy/Sort, Time Complexity: O(nlgn), Space Complexity: O(1) (n: boxTypes.size)
// 논리: numberOfUnitsPerBox가 큰 box 우선 선택. Sort/Heap으로 우선순위 높은 순 탐색가능.

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int answer = 0;
        
        sort(boxTypes.begin(), boxTypes.end(), [](auto& a, auto& b) { return b[1] < a[1];});
        
        for(int i=0;i<boxTypes.size();i++) {
            int boxCount = min(boxTypes[i][0], truckSize);
            answer += boxCount*boxTypes[i][1];
            truckSize -= boxCount;
        }
        return answer;
    }
};
