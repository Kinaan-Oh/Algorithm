// Sort, Time Complexity: O(nlgn), Space Complexity: O(k) (n: arr.size)

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto compare = [&](int a, int b) {
            return abs(a-x)<abs(b-x) || (abs(a-x)==abs(b-x) && a<b);
        };
        sort(arr.begin(), arr.end(), compare);
        sort(arr.begin(), arr.begin()+k);
        vector<int> answer(arr.begin(), arr.begin()+k);
        return answer;
    }
};
