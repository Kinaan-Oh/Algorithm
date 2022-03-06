// Math/Sort, Time Complexity: O(m+n), Space Complexity: O(1) (m: aliceSizes.size, n: bobSizes.size)
// 논리: 1) alice sum, bob sum의 차가 홀수이면 해는 존재할 수 없음. 교환으로 짝수값만큼 차를 줄일 수 있기 때문(1-1). 하지만, 문제는 반드시 해가 존재한다고 명시되어 있으므로, sum의 차는 짝수임이 보장된다.
//      1-1) alice 임의원소 a, bob 임의원소 b를 교환하면 sum difference를 2*(b-a)만큼 줄일 수 있음.
//      2) alice의 각 원소 e에 대하여 bob에 e + (bob sum - alice sum)/2 인 원소를 찾는(1-1에 의하여) 문제로 환원. (hash 혹은 sort+binary search 로 해결가능)

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int>  answer;
        unordered_set<int>  hashset;
        int sumA = 0;
        int sumB = 0;
        
        for(auto size: aliceSizes)  sumA += size;
        for(auto size: bobSizes) {
            sumB += size;
            hashset.insert(size);
        }
        
        for(auto size: aliceSizes) {
            if(hashset.find(size+(sumB-sumA)/2) != hashset.end()) {
                return {size, size+(sumB-sumA)/2};
            }
        }
        return {};
    }
};
