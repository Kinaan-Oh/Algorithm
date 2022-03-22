// Greedy/Heap, Time Complexity: O(), Space Complexity: O(n) (n: nums.size)
// 논리: 1) 각 num은 increase or decrease 가능.(둘 중 하나만)
//      2) min은 increase, max는 decrease하여 deviation을 줄여나가는 것은 다소 복잡한 논리로 발전
//         bst로 min, max를 동시관리가능하지만, 4가지 case(deviation을 줄이기 위해 min을 increase할지, max를 decrease할지, simultaneously min, max를 변환할지) 관리가 복잡.
//      3) 따라서, 단방향(max를 decrease or min을 increase)으로 진행.
//      3-1) 하단 풀이는 max를 decreas하는 방법을 선택. 이를위해, odd를 전부 max로 변환하는 preprocess 필요.
//      4) max를 효율적 탐색을 위해 heap structure 선택. (O(lgn))
//      5) max를 decrease할 수 없을때까지 반복하여, minimum deviation을 memoize.
//      5-1) decrease가 반드시 deviation의 decrease를 보장하지 않지만(cadidate에 불과), minimum deviation은 해당 cadidate에 반드시 포함된다.

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int answer = INT_MAX;
        int minNum = INT_MAX;
        priority_queue<int>  maxHeap;
        
        for(auto num: nums) {
            if(num%2) {
                minNum = min(minNum, 2*num);
                maxHeap.push(2*num);
            } else {
                minNum = min(minNum, num);
                maxHeap.push(num);
            }
        }
        
        while(!maxHeap.empty()) {
            int maxNum = maxHeap.top();
            maxHeap.pop();
            answer = min(answer, maxNum-minNum);
            
            if(maxNum%2) {
                break;
            } else {
                minNum = min(minNum, maxNum/2);
                maxHeap.push(maxNum/2);
            }
        }
        return answer;
    }
};
