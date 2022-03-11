// Queue, Time Complexity: O(n), Space Complexity: O(sz) (n: num of operations, sz: size of queue)
// 논리: Sliding Window 크기를 Queue의 Capacity로 설정. Capa를 넘어서면 queue의 front를 pop.

class MovingAverage {
private:
    queue<int>  que;
    int sz;
    int sum;
    
public:
    MovingAverage(int size) {
        sz = size;
        sum = 0;
    }
    
    double next(int val) {
        if(que.size()==sz)  {
            sum -= que.front();
            que.pop();
        }
        que.push(val);
        sum += val;
        return (double)sum/que.size();
    }
};
