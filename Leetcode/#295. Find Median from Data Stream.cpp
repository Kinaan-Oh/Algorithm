// Heap, Time Complexity: O(nlgn), Space Complexity: O(n) (n: num of operation addNum)
// 논리: 1) maxHeap은 하위 n~n+1개 유지, minHeap은 상위 n개 유지.
//      2-1) maxHeap size == minHeap size -> median = (maxHeap.top + minHeap.top)/2
//      2-2) maxHeap size > minHeap size -> median = maxHeap.top
//      3) addNum 정당성 증명
//      3-1) case 1) maxHeap size: n+1, minHeap size: n ->  1> maxHeap push 2> maxHeap pop and push the element to minHeap 3> size of maxHeap and min Heap are equal.
//      3-2) case 2) maxHea size: n, minHeap size: n -> same scenario as 3-1 and cause maxHeap size=minHeap size, we should pop from minHeap and push the elem to maxHeap.

class MedianFinder {
private:
    priority_queue<int>  maxHeap;
    priority_queue<int, vector<int>, greater<int>>  minHeap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        if(maxHeap.size()<minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        return maxHeap.size()==minHeap.size() ? (maxHeap.top()+minHeap.top())/(double)2 : maxHeap.top();
    }
};

// 동일 논리로 maxHeap n개, minHeap n+1개 유지하는 방법 또한 가능.

class MedianFinder {
private:
    priority_queue<int>  maxHeap;
    priority_queue<int, vector<int>, greater<int>>  minHeap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        
        if(maxHeap.size()>minHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        return maxHeap.size()==minHeap.size() ? (maxHeap.top()+minHeap.top())/(double)2 : minHeap.top();
    }
};


// 2022/04/04 ReDo

class MedianFinder {
private:
    priority_queue<int> maxHeap; // sz: n or n+1
    priority_queue<int, vector<int>, greater<int>>  minHeap; // sz: n
    
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        
        if(maxHeap.size()==minHeap.size()+2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()>minHeap.size())   return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) * 0.5;
    }
};
