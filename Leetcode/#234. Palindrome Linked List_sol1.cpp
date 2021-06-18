// "Two-Pointer", Time Complexity: O(n), Space Complexity: O(n).

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> list;
        for(ListNode* cur=head;cur!=nullptr;cur=cur->next) {
            list.push_back(cur->val);
        }
        int left = 0, right = list.size()-1;
        while(left<right) {
            if(list[left]!=list[right])    return false;
            left++, right--;
        }
        return true;
    }
};
