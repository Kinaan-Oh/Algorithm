// Time Limit Exceeded. update_order의 Time Complexity는 O(n) (n: cache.size). 따라서, get과 put의 Time Complexity도 O(n).
// update_order의 Time Complexity를 O(1)로 줄일 수 있는 방법이 필요함.

class LRUCache {
private:
    unordered_map<int,int>  cache;
    int capacity;
    deque<int> order;
    
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
            for(int i=0;i<order.size();i++) {
                if(order[i]==key) {
                    order.erase(order.begin()+i);
                }
            }
        }
        
        order.push_back(key);
    }
};
