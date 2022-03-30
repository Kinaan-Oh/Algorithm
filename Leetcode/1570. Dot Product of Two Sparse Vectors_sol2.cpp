// Two-Pointer, Time Complexity: O(n+m), Space Complexity: O(n+m) (n: nums.size, m: vec.nums.size)

class SparseVector {
public:
    vector<pair<int,int>>   v;
    
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++) {
            if(nums[i]) {
                v.push_back({i, nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int answer = 0;
        int p1 = 0;
        int p2 = 0;
        
        while(p1<v.size() && p2<vec.v.size()) {
            if(v[p1].first==vec.v[p2].first) {
                answer += v[p1].second * vec.v[p2].second;
                p1 += 1; p2 += 1;
            } else if(v[p1].first<vec.v[p2].first) {
                p1 += 1;
            } else {
                p2 += 1;
            }
        }
        return answer;
    }
};
