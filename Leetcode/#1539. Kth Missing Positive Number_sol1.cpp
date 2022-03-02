// Brute-Force, Time Complexity: O(n), Space Complexity: O(1) (n: arr.size)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(k<arr[0])    return k;
        k -= (arr[0]-1);
        
        for(int i=1;i<arr.size();i++) {
            if(k<=arr[i]-arr[i-1]-1)   return arr[i-1]+k;
            k -= (arr[i]-arr[i-1]-1);
        }
        return arr.back()+k;
    }
};
