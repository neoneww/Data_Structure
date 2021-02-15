/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
Tree* solve(LLNode* node)
{
    Tree *root;
    if(node == NULL)
    {
        return root;
    }   
    root = new Tree;
    root->val = node->val;
    root->left = NULL; root->right = NULL;
    if(node->next == NULL)
    {
        return root;
    }
    Tree *run = root;
    
    LLNode *prev = node;
    LLNode *curr = node->next;
    while(curr != NULL)
    {
        if(curr->val < prev->val)
        {
            Tree *lol = new Tree;
            lol->val = curr->val;
            run->left = lol;
            lol->left = NULL; lol->right = NULL;
            run = run->left;
        }
        else
        {
            Tree *lol = new Tree;
            lol->val = curr->val;
            run->right = lol;
            lol->left = NULL; lol->right = NULL;
            run = run->right;
        }

        prev = curr;
        curr = curr->next;
    }

    return root;

}
