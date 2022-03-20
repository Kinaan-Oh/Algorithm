// Heap, Time Complexity: O(nlgk), Space Complexity: O(n) (n: words.size)
// 논리: Heap을 역순으로 유지하여 상위k개만 유지함으로서 time complexity O(nlgk)로 최적화. 첫 풀이는 Heap을 평순으로 유지하지만, n개를 전부 push하는 부분이 bottle neck(O(nlgn))이 됨.

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>  answer;
        unordered_map<string, int>  freq;
        auto compare = [](pair<string,int>& a, pair<string,int>& b) {
            return a.second>b.second || (a.second==b.second && a.first<b.first);
        };
        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(compare)>   heap(compare);
        
        for(auto word: words) {
            freq[word] += 1;
        }
        
        for(auto elem: freq) {
            heap.push(elem);
            if(heap.size()>k)   heap.pop();
        }
        while(!heap.empty()) {
            answer.push_back(heap.top().first);
            heap.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};


// Heap, Time Complexity: O(nlgn), Space Complexity: O(n) (n: words.size)
// 첫 풀이

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>  answer;
        unordered_map<string, int>  freq;
        auto compare = [](pair<string,int>& a, pair<string,int>& b) {
            return a.second<b.second || (a.second==b.second && a.first>b.first);
        };
        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(compare)>   heap(compare);
        
        for(auto word: words) {
            freq[word] += 1;
        }
        
        for(auto elem: freq) {
            heap.push(elem);
        }
        for(int i=0;i<k;i++) {
            answer.push_back(heap.top().first);
            heap.pop();
        }
        return answer;
    }
};
