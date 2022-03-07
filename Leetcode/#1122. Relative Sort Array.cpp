// Hash/Sort, Time Complexity: O(nlgn), Space Complexity: O(m) (n: arr1.size, m: arr2.size)

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int>    pos;
        
        for(int i=0;i<arr2.size();i++) {
            pos[arr2[i]] = i;
        }
        
        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            if(pos.find(a)==pos.end() && pos.find(b)==pos.end()) {
                return a<b;
            } else if(pos.find(a)==pos.end()) {
                return false;
            } else if(pos.find(b)==pos.end()) {
                return true;
            }
            return pos[a]<pos[b];
        });
        return arr1;
    }
};
