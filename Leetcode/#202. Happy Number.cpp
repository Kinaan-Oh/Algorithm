// Two-Pointer(Floyd's Cycle Finding Algorithm), Time Complexity: O(lgn), Space Complexity: O(1) 

class Solution {
public:
    bool isHappy(int n) {
        int walker = n;
        int runner = n;
        
        do { 
            walker = getNext(walker);
            runner = getNext(getNext(runner));
            if(walker==1 || runner==1)  return true;
        } while(walker!=runner);
        return false;
    }
    
    int getNext(int n) {
        int sum = 0;
        
        while(n) {
            sum += (n%10)*(n%10);
            n /= 10;
        }
        return sum;
    }
};
