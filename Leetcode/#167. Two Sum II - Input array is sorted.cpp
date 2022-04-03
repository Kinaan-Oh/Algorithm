// "Two-Pointer", Time Complexity: O(n), Space Complexity: O(1). (n: numbers.size)
// left, right를 각각 오른쪽, 왼쪽 방향으로만 이동시키면서 문제 크기를 줄여나간다. 탐색중 답을 찾으면 리터.

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while(left<right) {
            if(numbers[left] + numbers[right] == target)    break;
            else if(numbers[left] + numbers[right] < target) left++;
            else right--;
        }
        return {left+1, right+1};
    }
};


// 2022/04/03 

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0;
        int p2 = numbers.size()-1;
        
        while(p1<p2) {
            int sum = numbers[p1] + numbers[p2];
            
            if(sum<target) {
                p1 += 1;
            } else if(sum>target) {
                p2 -= 1;
            } else {
                return {p1+1, p2+1};
            }
        }
        return {-1,-1};
    }
};
