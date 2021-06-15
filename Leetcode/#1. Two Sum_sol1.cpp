// "Two-pointer", Time Complexity: O(nlgn), Space Complexity: O(n)
// 이러한 탐색으로 nums의 원소를 반드시 찾아 낼 수 있는 이유는 결과론적으로 left와 right의 이동으로 Two Sum의 모든 조합을 만들어 낼 수 있기 때문이다. 흥미롭게도 O(n)내에 탐색은 종료된다.
// 결과와 동작원리는 이해는 가지만, 이 알고리즘의 근간이 되는 수학적 개념은 파악하지 못하였다.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>   sorted;
        for(int i=0;i<nums.size();i++)  sorted.push_back({nums[i],i});
        sort(sorted.begin(),sorted.end());
        int left=0, right=sorted.size()-1;
        while(left<right) {
            if(sorted[left].first+sorted[right].first<target) {
                left++;
            }
            else if(sorted[left].first+sorted[right].first>target) {
                right--;
            }
            else    return {sorted[left].second,sorted[right].second};
        }
        return {-1,-1};
    }
};
