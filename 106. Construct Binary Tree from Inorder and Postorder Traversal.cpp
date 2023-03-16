class Solution {
public:
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd){
        
        if(inStart > inEnd){
            return NULL;
        }
        
         TreeNode* root = new TreeNode(postorder[postEnd]);
        
         int i = inStart;
        
        for(; i <= inEnd; i++){
            
            if(inorder[i] == root->val)
                break;
        }
        
        int leftSize = i - inStart;
        int rightSize = inEnd - i;
        
        root->left = solve(inorder, postorder, inStart, i-1, postStart, postStart + leftSize-1);
        root->right = solve(inorder, postorder, i+1, inEnd, postEnd - rightSize, postEnd - 1);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        
        int inStart = 0;
        int inEnd = n-1;
        
        int postStart = 0;
        int postEnd = n-1;
        
        return solve(inorder,postorder,inStart,inEnd, postStart,postEnd);
    }
};

//buildTree function
//simply find size in N variable 
//find start and end of both order and call solve function

//solve function 
//parameter vector of inorder and postorder and starting and ending index of both
//if start is greater than end then ruturn NULL
//root wiil be post last element 
//for loop in inorder to find root(it will clear that which is left and right element of tree )
//find size of left and right 
//recursive cll for left and right 
//in argument we pass inorder, postorder, start=inorder(start), end =  newRoot - 1, postorder Value = postStart+LeftSize-1(-1for index)
//same for right 
//return root

