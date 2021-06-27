// 출제의도: "Design", Time Complexity: O(lg(n/k)), Space Complexity: O(m+k). (n: 가능한 모든 key의 값, k: bucket 갯수, m: 삽입한 원소 갯수)
// 해시 함수로 제산 함수(division)을 선택하였고 체이닝 기법을 사용하였다. 일반적으로 두 기법의 사용은 가장 좋은 성능을 낸다.
// 다만, 적재 밀도가 커지게 되면 성능이 떨어지고 다음과 같은 재조정이 필요하다.  1) 기존 해시테이블 크기의 2배인 해시테이블을 잡고  2) 해시 함수의 나눗셈 값을 새로운 해시 테이블 크기로 변경 해주고
// 3) 기존 해시테이블 원소를 새 해시테이블에 다시 삽입 한다. 
// 제조정은 굳이 구현하지는 않았다. 다만 정적 해싱의 재조정은 큰 오버헤드로 핵심 문제이고, 이는 동적 해싱(디렉터리 사용유무에 따라 유형이 갈림.)의 출현의 이유가 된다.

// 보통 정적 해싱에서 bucket을 배열로 구현하지만 이 경우 put의 Worst Case의 Time Complexity는 O(m)이 된다. map(Balanced Binary Tree) 자료구조를 이용한다면 Worst Case Time Complexity를
// O(lgm)으로 줄일 수 있다.

struct Bucket {
    map<int,int>  bucket;   // [key:value]
    
    void put(int key, int value) {
        bucket[key] = value;
    }
    
    int get(int key) {
        if(bucket.find(key) == bucket.end())    return -1;
        return bucket[key];
    }
    
    void remove(int key) {
        if(bucket.find(key) != bucket.end())    bucket.erase(key);
    }
};

struct HashTable {
    vector<Bucket>  buckets;
    
    void put(int key, int value) {
        buckets[(key)%4096].put(key,value);
    }
    
    int get(int key) {
        return buckets[key%4096].get(key);
    }
    
    void remove(int key) {
        buckets[key%4096].remove(key);
    }
    
    void resize(int size) {
        buckets.resize(size);
    }
};

class MyHashMap {
private:
    HashTable hashtable;
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        hashtable.resize(4096);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        hashtable.put(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return hashtable.get(key);
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        hashtable.remove(key);
    }
};
