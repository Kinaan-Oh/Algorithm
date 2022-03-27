// Greedy/Heap, Time Complexity: O(nlgn), Space Complexity: O(n) (n: a+b+c)
// 논리: 1) each time, we should choose alphabet which has maximun counts. then, add two of it to answer.
//      2) but, we should also consider that maximun length of consecutive sequence of same type should be less than 3.
//      2-1) So, each time we should choose maximum and second frequent alphabet.
//      3) But, we should add second frequent alphabet to answer carefully. if count of current maximum alphabet after adding to answer is less than second frequent alphabet,
//      we should add second frequent alphabet only once. else twice.

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string answer;
        auto compare = [](pair<char,int> &a, pair<char,int> &b) {
            return a.second<b.second;
        };
        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(compare)> heap(compare);
        
        if(a)   heap.push({'a',a});
        if(b)   heap.push({'b',b});
        if(c)   heap.push({'c',c});
        
        while(!heap.empty()) {
            pair<char,int> one = heap.top();
            heap.pop();
            if(one.first==answer.back())    break;
            
            answer += string(min(one.second,2),one.first);
            one.second -= min(one.second,2);
            
            if(!heap.empty()) {
                pair<char,int> two = heap.top();
                heap.pop();
                
                if(two.second>=2 && two.second>=one.second) {
                    answer += string(2, two.first);
                    two.second -= 2;
                } else {
                    answer += string(1, two.first);
                    two.second -= 1;
                }
                
                if(two.second)  heap.push(two);
            }
            
            if(one.second)  heap.push(one);
        }
        return answer;
    }
};
