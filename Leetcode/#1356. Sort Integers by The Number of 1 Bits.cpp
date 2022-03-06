// Sort/Bit Manipulation, Time Complexity: O(nlgn), Space Complexity: O(n) (n: arr.size)
// 논리: 1) 각 elem의 1의 갯수 결정 (O(num of bit 1)). b&(b-1) -> 최우측 1 제거 연산.
//      2) 결정된 count를 바탕으로 Sort.

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int, int>  count;
        
        for(auto elem: arr) {
            int cnt = 0;
            int value = elem;
            
            while(value) {
                cnt += 1;
                value = value&(value-1);
            }
            count[elem] = cnt;
        }
        
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if(count[a]==count[b])  return a<b;
            return count[a]<count[b];
        });
        return arr;
    }
};
