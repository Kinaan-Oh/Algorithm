// Binary Search/Sliding Window, Time Complexity: O(lgn+k), Space Complexity: O(k) (n: arr.size)
// 논리 : lower bound지점을 right로 직전 지점을 left하는 (left, right)에 포함되는 원소 갯수가 k개가 되도록 window를 적절하게 확장.

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right-1;
        
        while(k--) {
            if(right>=n || (left>=0 && abs(arr[left]-x)<=abs(arr[right]-x)))  left -= 1;
            else    right += 1;
        }
        vector<int> answer(arr.begin()+left+1, arr.begin()+right);
        return answer;
    }
};
