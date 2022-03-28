// Hash, Time Complexity: O(L), Space Complexity: O(L) (L: nums.size)
// 논리: 0이 아닌 요소만 Hash에 Memoize. Memoize된 요소가 target에 exists한다면, multiply and add product to answer.

class SparseVector {
public:
    unordered_map<int, int> ht;
    
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++) {
            if(nums[i]) {
                ht[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int answer = 0;
        for(auto elem: ht) {
            if(vec.ht.find(elem.first) != vec.ht.end()) {
                answer += elem.second*vec.ht[elem.first];
            }
        }
        return answer;
    }
};
