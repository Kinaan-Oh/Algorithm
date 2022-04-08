// BST, Time Complexity: 1) update: O(lgn), 2) current/maximum/minimum: O(1), Space Complexity: O(n) (n: num of update)
// 논리: 1) time/price ordered datastructure로 BST 선택. map, set/multiset은 BST 기반. min/max에 대한 참조를 유지하고 있고 O(1)로 접근할 수 있으므로 current/maximum/minimum
// 은 O(1).

class StockPrice {
private:
    map<int,int>    records; // (time: price)
    multiset<int>   prices;
public:
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        if(records.find(timestamp) != records.end()) {
            prices.erase(prices.find(records[timestamp]));
        }
        records[timestamp] = price;
        prices.insert(price);
    }
    
    int current() {
        return records.rbegin()->second;
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
};
