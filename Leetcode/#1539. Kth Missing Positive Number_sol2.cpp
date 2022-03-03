// Binary Search, Time Complexity: O(lgn), Space Complexity: O(1). (n: arr.size)
// 논리: arr상 Missing Possible Number가 k개 미만인 최초의 지점을 Binary Search로 찾기.
// 시행착오: 첫시도에 left = mid로 update하였고 무한루프 발생. left = mid+1로 update 해야만 하고, 종료시점 right가 찾고자 하는 지점이 된다.

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size()-1;
        
        while(left<=right) {
            int mid = left + (right-left)/2;
            
            if(arr[mid]-mid-1<k) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return k+right+1;
    }
};
