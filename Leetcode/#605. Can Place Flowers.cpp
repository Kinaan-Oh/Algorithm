// Greedy, Time Complexity: O(m), Space Complexity: O(1) (m: flowerbed.size)
// 논리: 단방향 탐색하면서 1) 현지점에 꽃이 없고 2) 좌우에 꽃이 없다면 꽃을 심는다.

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int flower = 0;
        
        for(int i=0;i<flowerbed.size();i++) {
            if(n==0)    return true;
            
            if(flowerbed[i]==0 && (i==0||flowerbed[i-1]==0) && (i==flowerbed.size()-1||flowerbed[i+1]==0)) {
                flowerbed[i] = 1;
                n -= 1;
            }
        }
        return n==0;
    }
};
