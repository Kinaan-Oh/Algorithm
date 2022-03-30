// Two-Pointer, Time Complexity: O(n), Space Complexity: O(1) (n: nums.size)
// 논리:  1) Two-Pointer 탐색을 위해 Sort.
//       2) 조건 i != j, nums[i] - nums[j] == k 인 pair을 탐색하기 위해 포인터 p1(left), p2(right) 초기 위치를 0, 1로 설정
//       3) gap>k 이면 p1+=1, gap<k 이면 p2+=1.
//       gap==k 이면, answer+=1 distinct pair를 찾아야하기 때문에 중복성 처리 필요. p1 혹은 p2를 current val과 다른 최초의 지점으로 update. 둘다 통과하지만, 하단 풀이는 전자.

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int answer = 0;
        int n = nums.size();
        int p1 = 0;
        int p2 = 1;
        sort(nums.begin(), nums.end());
        
        while(p1<n && p2<n) {
            if(p1==p2 || nums[p2]-nums[p1]<k) {
                p2 += 1;
            } else if(nums[p2]-nums[p1]>k) {
                p1 += 1;
            } else {
                answer += 1;
                
                p1 += 1;
                while(p1<n && nums[p1]==nums[p1-1]) {
                    p1 += 1;
                }
            }
        }
        return answer;
    }
};
