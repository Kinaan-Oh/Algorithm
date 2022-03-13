// Two-Pointer, Time Complexity: O(n), Space Complexity: O(1) (n: chars.size)
// N사 코테와 유사

class Solution {
public:
    int compress(vector<char>& chars) {
        int answer = 0;
        int p1 = 0; // read
        int p2 = 0; // write
        
        char prev = chars[0];
        int count = 1;
        
        for(int i=1;i<chars.size();i++) {
            if(prev==chars[i]) {
                count += 1;
            } else {
                string n = string(1, prev);
                n += count==1 ? "" : to_string(count);

                for(auto c: n) {
                    chars[p2++] = c;
                }
                prev = chars[i];
                count = 1;
            }
        }
        
        string n = string(1, prev);
        n += count==1 ? "" : to_string(count);
        
        for(auto c: n) {
            chars[p2++] = c;
        }
        
        return p2;
    }
};
