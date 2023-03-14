class Solution {
public:
    int solve(TreeNode* root,int curr){
        if(!root)
            return 0;
        
        curr = (curr*10) + root->val;
        
        if(root->left == NULL && root->right == NULL){
            return curr;
        }
        
        int l = solve(root->left,curr);
        int r = solve(root->right,curr);
        
        return l+r;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};

//line 30 we return a fuction name solve in function we pass root and curr val 0

//in solve function
//if root is equal to null so return 0 
//if not then in current miltiply the curr with 10 and add the value of root 
//and in l we call solve function and pass root left and curr 
//example :      3
//           2    
//        1
//  so here fir curr = 0 then come to root so curr become 3 then again left is call this time 2*10=20   20+3 = 23 then again left is call value become 23*10=230   230+1= 231  231 store in l 
//same for r   
//and return l+r
