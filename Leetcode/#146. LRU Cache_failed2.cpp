// update_order를 개선하기 위해 deque를 list(doubly linked list) 자료구조로 교체. list.erase는 Time Complexity O(1)로 deque.erase의 Time Complexity O(n)보다 앞선다.
// key를 선형탐색하므로, update_order의 Time Complexity는 개선되었지만 여전히 O(n).
// Time Limit Exceeded. failed1은 테스트케이스 19개를 통과했으나, list로 교체하여 20개를 통과. 그러나, Time Complexity 측면에서 유의미한 개선은 아니었음. 
// "order에서 특정 key 탐색을 O(n)에서 O(1)로 줄여야만 한다."

class LRUCache {
private:
    unordered_map<int,int>  cache;
    int capacity;
    list<int> order;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end())   return -1;
        
        update_order(key);
        return cache[key];
    }
    
    void put(int key, int value) {
        if(cache.size()==capacity && cache.find(key)==cache.end()) {
            evict();
        }
        
        update_order(key);
        cache[key] = value;
    }
    
    void evict() {
        cache.erase(order.front());
        order.pop_front();
    }
    
    void update_order(int key) {
        if(cache.find(key)!=cache.end()) {
            order.remove(key);
        }
        
        order.push_back(key);
    }
};
