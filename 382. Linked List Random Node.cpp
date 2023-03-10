//Better Approach (Using Reservior Sampling) - Timr : O(n)
class Solution {
public:
    ListNode* temp;
    Solution(ListNode* head) {
        temp = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res;
        ListNode* curr = temp;
        int size = 1;
        while(curr) {
            //choosing probability is 1/size (reservior sampling)
            if(rand()%size == 0)
                res = curr->val;
            curr = curr->next;
            size++;
        }
        return res;
    }
};
