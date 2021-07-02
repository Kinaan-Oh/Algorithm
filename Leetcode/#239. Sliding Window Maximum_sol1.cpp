// "multiset(Balanced Multi BST)", Time Complexity: O(nlgk), Space Complexity: O(n). (n: nums.size)
// "2019 카카오인턴 징검다리건너기"와 사실상 동일한 문제.
// 1) 내부적으로 정렬된 2) 중복 원소를 허용하는 3) 임의 원소의 삭제가 가능한 자료구조인 multiset을 선택. C++의 priority_queue는 임의 원소 삭제를 제공하지 않음.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int>  bst;
        
        for(int i=0;i<k;i++)    bst.insert(nums[i]);
        ans.push_back(*(--bst.end()));
        
        for(int i=k;i<nums.size();i++)
        {
            bst.insert(nums[i]);
            bst.erase(bst.find(nums[i-k]));
            ans.push_back(*(--bst.end()));
        }
        return ans;
    }
};
