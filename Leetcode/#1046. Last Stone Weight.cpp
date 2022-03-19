// Heap, Time Complexity: O(nlgn), Space Complexity: O(n) (n: stones.size)

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int answer = 0;
        priority_queue<int> maxHeap(begin(stones), end(stones));
        
        while(maxHeap.size()>1) {
            int st1 = maxHeap.top();
            maxHeap.pop();
            int st2= maxHeap.top();
            maxHeap.pop();
            int diff = abs(st1-st2);
            if(diff)  maxHeap.push(diff);  
        }
        if(!maxHeap.empty())    answer = maxHeap.top();
        return answer;
    }
};
