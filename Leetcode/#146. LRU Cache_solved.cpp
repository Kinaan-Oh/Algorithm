// key의 list상 위치(iterator)을 해시 테이블로 따로 관리하여, failed2의 update_order의 key탐색 Time Complexity를 O(n)에서 O(1)로 개선.
// list.erase는 iterator타입만 인자로 받기 때문에, iterator를 위치정보로 이용해야만 함. 고민한 부분은 vector의 경우 원소의 삽입/삭제시 resize되어 다른 원소에 대한 iterator가 무효화된다는 문제점이 있는데,
// list는 그런 문제점이 있지 않을까하는 것이었다. 조사한 결과 list의 삽입/삭제시 resize가 일어나지 않으므로 다른 원소에 대한 iterator는 보존된다. 따라서, iterator를 포인터처럼 활용할 수 있게된다.
// 결과적으로 해시테이블과 리스트(doubly linked list) 자료구조를 이용하여 get과 put의 Time Complexity를 O(1)로 구현할 수 있었다.

// refactor: 1/18. pair를 이용하여 단일 hash 사용.

class LRUCache {
private:
    int capacity;
    unordered_map<int, list<pair<int,int>>::iterator>  pos;
    list<pair<int,int>>   list; // (key:value)
    
public:
    LRUCache(int input) {
        capacity = input;
    }
    
    int get(int key) { 
        if(pos.find(key) == pos.end())  return -1;
        
        update_pos(key);
        return pos[key]->second;
    }
    
    void put(int key, int value) {
        if(pos.find(key) != pos.end()) {
            update_pos(key);
            pos[key]->second = value;
            return;
        }
        
        if(list.size() == capacity)    evict();
        list.push_back({key, value});
        pos[key] = --list.end();
    }
    
    void update_pos(int key) {
        list.push_back(*pos[key]);
        list.erase(pos[key]);
        pos[key] = --list.end();
    }
    
    void evict() {
        pos.erase(list.front().first);
        list.pop_front();
    }
};
