class Solution {
public:
    
     ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2){
         
         if(!l1) return l2;
         if(!l2) return l1;
         
         if(l1->val <= l2->val){
            
         l1->next = mergeTwoSortedLists(l1->next, l2);
             
             return l1;
         }
         else{
             
             l2->next = mergeTwoSortedLists(l2->next, l1);
             
             return l2;
         }
         
         return NULL;
         
     }
    
    ListNode* partionAndMerge(int start, int end, vector<ListNode*>& lists){
        
        if(start > end){
            return NULL;
        }
        if(start == end){
            return lists[start];
        }
        
        int mid = start + (end-start)/2;
        
       ListNode*  l1 = partionAndMerge(start, mid, lists);
        
        ListNode* l2 = partionAndMerge(mid+1, end, lists);
        
       return mergeTwoSortedLists(l1, l2);
    }
         
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int k = lists.size();
        
        if(k == 0)
            return NULL;
        return partionAndMerge(0, k-1, lists);
    }
};
//Approach-1 (Using merge sort) - Time : O(log(k) * k * n)

 //   Where k = total number of lists if k is 0 then return NULL and else we call partionAndMerge function

//mergeTwoSortedLists function 

//in this we pass 2 linklist 
//if l1 is empty then return l2 same for l2 
//if l1 value is small that l2  so return l1 and recursively call mergeTwoSortedLists function and pass l1 next //(bcoz l1 is return) and l2  
//and same for l2

//partionAndMerge function

//if start and end both are equal that means list have 1 val so return start
//find mid 
//divide in 2 and call partionAndMerge function for start mid and another for mid+1 to end
