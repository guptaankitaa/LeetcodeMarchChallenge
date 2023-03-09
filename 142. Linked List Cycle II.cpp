class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || (head->next == NULL))
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast-> next != NULL){
            slow = slow -> next;
            fast = fast->next->next;
            
            if(slow == fast)
                break;
        }
        
        if(slow != fast)
            return NULL;
       
        ListNode* p = head;
        
        while(p != slow){
            p = p->next;
            slow = slow->next;
        }
        return slow;
    }
};
    
    class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow = head, *fast = head;
        
        while (fast && fast->next) {
            
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        
        if (!(fast && fast->next)) return NULL;
        
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};


Using slow and Fast Pointer 
here both stand at index 0 means at head of list 
then slow moves 1 step and fast move 2 step 
loop execute till if fast and fast next is present 
if yes move slow 1 step and fast 2 step 
if boot are equal Lie at same place then the cycle is there 
now we take anoter pointer from head we move it 1 step and same move slow 1 step till both lie at same place that is the start of cycle

 Time = O(n), Space = O(1)

L1 = length of list till the loop start          L2 = length of half loop              n = rounds of circle       

slow = L1 + L2
fast = L1 + L2 + n

fast = twice (slow)
2(L1 + L2) = fast
2(L1 + L2) L1 + L2 + n      => L1 + L2 = n
L1 = nk - L2 
that means L1 is equal to remaining part of loop thats why we take another pointer

    
