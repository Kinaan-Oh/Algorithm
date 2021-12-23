// 출제의도: String, Time Complexity: O(n), Space Complexity: O(n). (n: paragraph.length)

bool skip(char c) {
    if(ispunct(c) || c==' ') {
        return true;
    }
    return false;
}

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int>  freq;
        unordered_set<string>   words;
        unordered_set<string>   banned_words;
        string word;
        string answer;
        
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        
        for(auto banned_word: banned) {
            banned_words.insert(banned_word);
        }
        
        for(int i=0;i<paragraph.length();i++) {
            if(skip(paragraph[i])) {
                if(i>0 && !skip(paragraph[i-1])) {
                    if(banned_words.find(word) == banned_words.end()) {
                        words.insert(word);
                        freq[word] += 1;
                    }
                    
                    word.clear();
                }
            } else {
                word.push_back(paragraph[i]);
                
                if(i==paragraph.length()-1 && banned_words.find(word) == banned_words.end()) {
                    words.insert(word);
                    freq[word] += 1;
                }
            }
        }
        
        int max_freq = INT_MIN;
        for(auto word: words) {
            if(max_freq<freq[word]) {
                max_freq = freq[word];
                answer = word;
            }
        }
        
        return answer;
    }
};
