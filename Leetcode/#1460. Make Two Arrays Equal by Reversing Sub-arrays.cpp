// Sort, Time Complexity: O(nlgn), Space Complexity: O(1) (n: target.size)
// 논리: 1) 2회의 reverse로 두 원소의 swap 표현가능.
//      2) 따라서, reverse를 통해 정렬가능(ex: bubble sort는 swap을 이용한 정렬방법)함이 보장됨.
//      3) 두 배열을 정렬 후, 두 배열의 원소가 순차적으로 동일하다면 true.

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        
        for(int i=0;i<target.size();i++) {
            if(target[i]!=arr[i]) {
                return false;
            }
        }
        return true;
    }
};
