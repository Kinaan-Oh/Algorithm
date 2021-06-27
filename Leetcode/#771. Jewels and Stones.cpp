// 출제의도: "hash table/hash set", Time Complexity: O(m+n), Space Complexity: O(m) (m: jewels.size, n: stones.size)

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        unordered_set<char>  is_jewel;
        for(int i=0;i<jewels.size();i++)    is_jewel.insert(jewels[i]);
        for(int i=0;i<stones.size();i++) {
            if(is_jewel.find(stones[i]) != is_jewel.end()) {
                ans++;
            }
        }
        return ans;
    }
};
