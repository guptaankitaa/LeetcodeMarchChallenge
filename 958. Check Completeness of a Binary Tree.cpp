class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> que;
        
        que.push(root);
        
        bool past = false;
        
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            
            if(node == NULL){
                past = true;
            } else {
                if(past == true){
                    return false;
                }
                
                que.push(node->left);
                que.push(node->right);
            }
        }
        return true;
    }
};

//Using BFS 
//taking a queue name que
//push root in que 
//make a variable bool type initialy its false (it is to keep record of NULL node)
//while loop till que is equal to not null
//if node is null so we mark past true (means there is a nullvnode)
//else if past is true then return false (bcoz there is a null in queue)
//recusive call left and right

