// 출제의도: custum sort/ stable sort, Time Complexity: O(mnlgn), Space Complexity: O(1). (n: logs.size, m: maximum of log.size)

bool compare(string a, string b) {
    int pos_a = a.find(" ");
    int pos_b = b.find(" ");
    
    if(isalpha(a[pos_a+1]) && isdigit(b[pos_b+1])) {
        return true;
    } else if(isalpha(a[pos_a+1]) && isalpha(b[pos_b+1])) {
        if(a.substr(pos_a+1)==b.substr(pos_b+1)) {
            return a.substr(0,pos_a)<b.substr(0,pos_b);
        }
        return a.substr(pos_a+1)<b.substr(pos_b+1);
    }
    return false;
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), compare);
        
        return logs;
    }
};
