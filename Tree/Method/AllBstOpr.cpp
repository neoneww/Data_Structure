
//----------------Insertion-------------------------//

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
        {
            TreeNode *start = new TreeNode(val);
            return start;
        }
        else if(val < root->val)
        {
            root->left = insertIntoBST(root->left,val);
        }
        else if(val > root->val)
        {
            root->right = insertIntoBST(root->right,val);
        }
        
        return root;
    }
};

//--------------------------Searching-----------------//

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
        {
            return NULL;
        }
        else if(val > root->val)
        {
            return searchBST(root->right,val);
        }
        else if(val < root->val)
        {
            return searchBST(root->left,val);
        }
        
        return root;
    }
};

//----------------delete----------------//

//deleting node with two children = is either get the max from left sub tree or min from the right subtree then go to that node and delete that node 
// delete node with no children is just delete the node 
// with 1 childere just attach the subtree below the node which has to be deleted

//our delete node function will just connect a node to another subtree 

class Solution {
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
    
        if(!root)
            return NULL;
        
        if(root->val > key)
            root->left = deleteNode(root->left, key);
        
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        
    
        else{
            
           if(!root->left && !root->right){
               delete(root);
               return NULL;
           }
            
            if(!root->left || !root->right){
                TreeNode *child = root->left? root->left : root->right;
                delete(root);
                return child;
            }
            
            TreeNode * left = root->left;
            TreeNode * right = root->right;
            root = root->left;
            
            while(root->right){
                root = root->right;
            }
            
            root->right = right;
            return left;
        }
        
        return root;
    }
};
