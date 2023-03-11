class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return NULL;
        if(!head->next)
            return new TreeNode(head->val);
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slow_prev = NULL;
        
        while(fast != NULL && fast->next != NULL){
            
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        
        slow_prev->next = NULL;
        
        root->left = sortedListToBST(head);
        
        root->right =sortedListToBST(slow->next);
        
        return root;
    }
};
//TimeComp = 0(n logn)      SpaceComp = 0(1)

//edge case if head is null return null and if head next is null then return head
//making 3 pointer slow point head fast point head and slowprev point null
//while loop execute till fast not be null and fast next also not be null
//then slowprev point slow and slow point next node and fast point next to next node
//now it is sure that slow is at mid 
//so now we make treenode and root will be value of slow
//ans our slowprev point point null
//then we recursively call left head and for right head should be slow next 
