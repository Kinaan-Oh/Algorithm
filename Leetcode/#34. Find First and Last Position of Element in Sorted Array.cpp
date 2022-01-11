// 출제의도: Binary Search, Time Complexity: O(lgn), Space Complexity: O(1). (n: nums.size)
// binary search 응용. target과 일치하는 대상이 여러개일 때, 일치하는 첫번째 그리고 마지막을 각각 binary search로 탐색 가능.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)  return {-1,-1};
        
        vector<int> answer;
        answer.push_back(find_first_of(nums, 0, nums.size(), target));
        answer.push_back(find_last_of(nums, 0, nums.size(), target));
        return answer;
    }
    
    int find_first_of(vector<int>& nums, int begin, int end, int target) {
        if(begin==end)  return (end==nums.size() || nums[end]!=target) ? -1 : end;
        
        int mid = (begin+end)/2; 
        if(nums[mid]<target)   return find_first_of(nums, mid+1, end, target);     
        else    return find_first_of(nums, begin, mid, target);  
    }
    
    int find_last_of(vector<int>& nums, int begin, int end, int target) {
        if(begin==end)  return (begin==0 || nums[begin-1]!=target) ? -1 : begin-1;
        
        int mid = (begin+end)/2;
        if(nums[mid]<=target)   return find_last_of(nums, mid+1, end, target);
        else return find_last_of(nums, begin, mid, target);
    }
};
