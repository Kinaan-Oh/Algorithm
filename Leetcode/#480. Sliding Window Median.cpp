// 논리: 1) min heap,max heap으로 median 탐색
//      2) window slide 과정에서 front element를 invalidate 필요. 직접 탐색 -> Time Complexity: O(nklgk) 으로 비효율적. 따라서, Lazy Removal Method 적용.
//      3) Lazy Removal을 위해 Invalidated element를 memoize할 HashTable 필요.
//      4) min heap, max heap의 `Valid Element 기준` balancing(n+1:n or n:n+1). Balancing과 관련하여 디테일한 로직 필요.
//      5) 각 min heap, max heap의 top이 Invalid 하면(hashtable 조회) lazy remove(pop).
//      6) For each window sliding, we need O(lgk). So, Total Time Complexity is O(nlgk).
// 추후 좀더 간결하게 정리 필요.

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double>  answer;
        int n = nums.size();
        priority_queue<int> maxHeap; 
        priority_queue<int, vector<int>, greater<int>>  minHeap;
        unordered_map<string,int>  validNum; // key: "maxHeap", "minHeap"
        unordered_map<int,int>  maxHeapInValidNum; // num: cnt
        unordered_map<int,int>  minHeapInValidNum; // num: cnt
        
        // maxHeap valid elem : minHeap valid elem = (n or n+1) : n
        for(int i=0;i<k;i++) {
            maxHeap.push(nums[i]);
        }
        for(int i=0;i<k/2;i++) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
        validNum["maxHeap"] = maxHeap.size();
        validNum["minHeap"] = minHeap.size();
        
        for(int i=k;i<=n;i++) {
            answer.push_back(k&1 ? maxHeap.top() : ((double)maxHeap.top() + (double)minHeap.top()) * 0.5);
            if(i==n)    break;
            
            int in = nums[i];
            int out = nums[i-k];
          
            // Invalidate
            if(out<=maxHeap.top()) {
                maxHeapInValidNum[out] += 1;
                validNum["maxHeap"] -= 1;
            } else {
                minHeapInValidNum[out] += 1;
                validNum["minHeap"] -= 1;
            }
            
            // Balancing 
            minHeap.push(in);
            while(minHeapInValidNum[minHeap.top()]) {
                minHeapInValidNum[minHeap.top()] -= 1;
                minHeap.pop();
            }
            maxHeap.push(minHeap.top());
            minHeap.pop();
            validNum["maxHeap"] += 1;
            while(validNum["maxHeap"] > validNum["minHeap"]+1) {
                if(maxHeapInValidNum[maxHeap.top()]) {
                    maxHeapInValidNum[maxHeap.top()] -= 1;
                    maxHeap.pop();
                } else {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    validNum["maxHeap"] -= 1;
                    validNum["minHeap"] += 1;
                }
            }
            
           // Remove Invalid top elements 
            while(maxHeapInValidNum[maxHeap.top()]) {
                maxHeapInValidNum[maxHeap.top()] -= 1;
                maxHeap.pop();
            }
            while(minHeapInValidNum[minHeap.top()]) {
                minHeapInValidNum[minHeap.top()] -= 1;
                minHeap.pop();
            }
        }
        return answer;
    }
};
