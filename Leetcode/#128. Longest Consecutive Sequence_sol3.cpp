// Time Complexity: O(nlg*n), Space Complexity: O(n) (n: nums.size)
// union_by_height , find(path-compression) -> n개의 포리스트 생성, union/find의 n번 반복수행시 nlg*n의 시간복잡도.(lg* : log star)

class Solution {
private:
     unordered_map<int,int>  parent;
     unordered_map<int,int>  height;
     unordered_map<int,int>  sz;
    
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_map<int,bool> visited;
        
        for(int i=0;i<nums.size();i++)  {
            parent[nums[i]] = nums[i];
            sz[nums[i]] = 1;
        }

        for(int i=0;i<nums.size();i++) {
            if(visited[nums[i]])    continue;
            
            visited[nums[i]] = true;
            int prev = nums[i]-1, next = nums[i]+1;
            
            if(parent.find(prev)!=parent.end() && !visited[prev]) {
                union_by_height(prev,nums[i]);
            }
            
            if(parent.find(next)!=parent.end() && !visited[next]) {
                union_by_height(next,nums[i]);
            }
        }
        for(auto it=sz.begin();it!=sz.end();it++)   ans = max(ans,it->second);
        return ans;
    }
    
    int find(int n) {
        if(parent[n]==n)    return n;
        return parent[n] = find(parent[n]);
    }
    
    void union_by_height(int n, int m) {
        int root_n = find(n);
        int root_m = find(m);
        if(root_n==root_m)  return;
        
        if(height[root_n]==height[root_m]) {
            parent[root_n] = root_m;
            height[root_m]++;
            sz[root_m] += sz[root_n];
        }
        else if(height[root_n]<height[root_m]) {
            parent[root_n] = root_m;
            sz[root_m] += sz[root_n];
        }
        else {
            parent[root_m] = root_n;
            sz[root_n] += sz[root_m];
        }
    }
};
