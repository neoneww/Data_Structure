/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
        {
            return root;
        }

        queue<Node*> pendingNodes;
        pendingNodes.push(root);
        root->next = NULL;
        queue<Node*> removal;

        while(pendingNodes.empty() != true)
        {
                int cnt = pendingNodes.size();
                Node *temp = NULL;
                while(cnt--)
                {
                    Node *front = pendingNodes.front();
                    pendingNodes.pop();
                    if(front->right != NULL)
                    {
                        pendingNodes.push(front->right);
                        removal.push(front->right);
                    }
                    if(front->left != NULL)
                    {
                        pendingNodes.push(front->left);
                        removal.push(front->left);
                    }
                }

                while(removal.empty() != true)
                {
                    Node *top = removal.front();
                    removal.pop();
                    top->next = temp;
                    temp = top;
                }
        }

        return root;
        
    }
};
