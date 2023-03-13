class Solution {
public:
    
    bool match(TreeNode* root1, TreeNode* root2){
        if(root1 != NULL && root2 != NULL){
            bool a = match(root1->left, root2->right);
            bool b = match(root1->right, root2->left);
            
            if((root1->val == root2->val) && a && b)
                return true;
            else
                return false;
            
        }
        else if(root1 == NULL && root2 == NULL){
            return true;
        }else
            return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        
        return match(root->left, root->right);
    }
};

//line 33   if root is null then it is symmetric so return true
//ans we return match function in this we pass left  and right of root

//in match function 
//if root1 is not null and root2 is also not null 
//so we make a bool variable and call root1 left and root2 right (bcoz its a mirrior so what is right in mirror it show as left)
//same for b 
//and after this we check value and equivalency of a and b
//if equal return true else false 
//edge case if root1 is null and root 2 is also null so we return true else false
