// Binary Search, Time Complexity: O(nlgn), Space Complexity: O(1) (n: nums.size)
// duplicate이 단 하나라는 조건으로 각 후보(1~n)에 대해 이분탐색이 가능.
// ex) 1555556 라는 나열이 있을 때, 중복값 5보다 작은 수 a에 대하여 [1,a]에 속하는 수의 갯수는 반드시 a보다 같거나 작다.
// 반대로 중복값 5이상의 수 b에 대하여 [b,6]에 속하는 수의 크기는 반드시 b보다 크다.
// 이러한 논리로 탐색구간을 시행당 절반으로 줄여나갈 수 있다. 따라서, lgn회 탐색이 진행되고 각 탐색당 O(n)이 걸리므로 time complexity = O(nlgn)이 된다.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate;
        int begin = 1;
        int end = nums.size();

        while(begin<end) {
            int mid = (begin+end)/2;
            
            if(equal_or_less(nums, mid) <= mid)    begin = mid+1;
            else {
                duplicate = mid;
                end = mid;
            }
        }
        return duplicate;
    }
    
    int equal_or_less(vector<int>& nums, int n) {
        int count = 0;
   
        for(auto num: nums) {
            if(num <= n)    count += 1;
        }
        return count;
    }
};
