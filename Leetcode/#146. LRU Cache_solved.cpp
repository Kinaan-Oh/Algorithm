// key의 list상 위치(iterator)을 해시 테이블로 따로 관리하여, failed2의 update_order의 key탐색 Time Complexity를 O(n)에서 O(1)로 개선.
// list.erase는 iterator타입만 인자로 받기 때문에, iterator를 위치정보로 이용함. 고민한 부분은 vector의 경우 원소의 삽입/삭제시 resize되어 다른 원소에 대한 iterator가 무효화된다는 문제점이 있는데,
// list는 그런 문제점이 있지 않을까하는 것이었다. 조사한 결과 list의 삽입/삭제시 resize가 일어나지 않으므로 다른 원소에 대한 iterator는 보존된다. 따라서, iterator를 포인터처럼 활용할 수 있게된다.
// 정리하면, 해시테이블과 리스트(doubly linked list) 자료구조를 이용하여 get과 put의 Time Complexity를 O(1)로 구현할 수 있었다.

class LRUCache {
private:
    unordered_map<int,int>  cache;
    int capacity;
    list<int> order;
    unordered_map<int,list<int>::iterator> pos_in_order;
    
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
            order.erase(pos_in_order[key]);
        }
        
        order.push_back(key);
        pos_in_order[key] = --order.end();
    }
};
