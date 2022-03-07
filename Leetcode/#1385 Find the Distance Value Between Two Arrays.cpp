// Sort/Binary Search, Time Complexity: O((m+n)lgn), Space Complexity: O(1) (m: arr1.size, n:arr2.size)
// 논리: arr1 각 원소에 대하여 abs(arr1[i]-arr2[mid])<=d을 만족하는 arr2 원소를 binary search. (binary search를 위해 arr2 우선 sort 필요)

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int answer = 0;
        
        sort(arr2.begin(), arr2.end());
        
        for(int i=0;i<arr1.size();i++) {
            bool fnd = false;
            int left = 0;
            int right = arr2.size()-1;
            
            while(left<=right) {
                long long mid = left + (right-left)/2;
                
                if(abs(arr1[i]-arr2[mid])<=d) {
                    fnd = true;
                    break;
                } else if(arr1[i]<arr2[mid]) {
                    right = mid-1;
                } else if(arr1[i]>arr2[mid]) {
                    left = mid+1;
                }
            }
            
            if(!fnd)    answer += 1;
        }
        return answer;
    }
};
