// Heap, Time Complexity: O(nlgn+mlgk), Space Complexity: O(n) (n: nums.size, m: num of operation add)
// 논리: 상위 k개만 유지하기 위해, min heap으로 최하위 원소부터 제거.

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto num: nums) {
            minHeap.push(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        while(minHeap.size()>K) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
